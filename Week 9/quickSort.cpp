#include <iostream>
using namespace std;

int partition(int left, int right, int a[], int n) {
    int pivot = a[left];
    int count = 0;

    for (int i = left + 1; i <= right; i++) {
        if(a[i] <= pivot)
            count++;
    }

    int p = left + count;
    swap(a[left], a[p]);

    int i = left, j = right;

    while(i < p && j > p) {
        while(a[i] < pivot) {
            i++;
        }
        while(a[j] > pivot) {
            j--;
        }
        swap(a[i], a[j]);
    }

    return p;
}

void quickSort(int left, int right, int a[], int n) {
    if(left < right) {
        int p = partition(left, right, a, n);
        quickSort(left, p - 1, a, n);
        quickSort(p + 1, right, a, n);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i];

        if (i != n-1)
            cout << " ";
    }
    cout << endl;
}

int main() {
    int arr[10] = {51, 95, 66, 72, 42, 38, 39, 41, 15};
    int n = 10;

    quickSort(0, 9, arr, n);

    printArray(arr, n);

    return 0;
}