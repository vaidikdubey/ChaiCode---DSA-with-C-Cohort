#include <iostream>
using namespace std;

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
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

    int arr[6] = {12, 8, 2, 4, 5, 1};
    int n = 6;

    bubbleSort(arr, n);

    printArray(arr, n);

    return 0;
}