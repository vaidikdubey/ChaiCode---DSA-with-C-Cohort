#include <iostream>
using namespace std;

void combine(int left, int mid, int right, int a[], int n) {
    int n1 = mid - left + 1; //Left array length
    int n2 = right - mid; //Right array length
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) { //Copy left array elements
        L[i] = a[left + i];
    }
    for (int j = 0; j < n2; j++) { //Copy right array elements
        R[j] = a[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) { //Combine with sorting
        if(L[i] < R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    //Handle remaining elements (if any)
    while(i < n1) {
        a[k++] = L[i++];
    }

    while (j < n2)
    {
        a[k++] = R[j++];
    }
}

void mergeSort(int left, int right, int a[], int n) {
    if(left < right) {
        int mid = left + (right - left) / 2; //Define mid

        //Divide array
        mergeSort(left, mid, a, n);
        mergeSort(mid + 1, right, a, n);
        
        //Combine array
        combine(left, mid, right, a, n);
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

    int arr[7] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;

    mergeSort(0, n-1, arr, n);

    printArray(arr, n);

    return 0;
}