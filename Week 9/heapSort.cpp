#include <iostream>
using namespace std;

void heapify(int n, int i, int a[], int size) {
    int parent = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && a[left] > a[parent]) {
        parent = left;
    }
    if(right < n && a[right] > a[parent]) {
        parent = right;
    }

    if(parent != i) {
        swap(a[i], a[parent]);
        heapify(n, parent, a, size);
    }
}

void heapSort(int n, int a[], int size) {
    for (int i = n / 2; i >= 0; i--) {
        heapify(n, i, a, size);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(i, 0, a, size);
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

    int arr[6] = {12, 11, 13, 5, 8, 7};
    int size = 6;

    heapSort(size, arr, size);
    
    printArray(arr, size);

    return 0;
}