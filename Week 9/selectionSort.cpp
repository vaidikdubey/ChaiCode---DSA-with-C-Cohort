#include <iostream>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if(a[j] < a[min]) {
                min = j;
            }
        }
        swap(a[i], a[min]);
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

    int arr[8] = {7, 2, 56, 12, 89, 32, 4, 27};
    int n = 8;

    selectionSort(arr, n);

    printArray(arr, n);

    return 0;
}