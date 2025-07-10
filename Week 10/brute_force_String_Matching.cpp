#include <iostream>
using namespace std;

int stringMatching(char T[], char P[], int n, int m) {
    for (int i = 0; i < n - m; i++) {
        int j = 0;

        while(j < m && T[i + j] == P[j]) {
            j++;
        }

        if(j == m)
            return i;
    }

    return -1;
}

int main() {
    char T[] = "abcabbcdacbd";
    char P[] = "bcda";

    int n = sizeof(T) - 1;
    int m = sizeof(P) - 1;

    cout << "Pattern found at index: " << stringMatching(T, P, n, m)  << endl;

    return 0;
}