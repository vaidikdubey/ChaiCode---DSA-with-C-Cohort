#include <iostream>
using namespace std;

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
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

    int arr[7] = {56, 2, 89, 23, 87, 32, 453};
    int n = 7;

    insertionSort(arr, n);

    printArray(arr, n);
    
    return 0;
}