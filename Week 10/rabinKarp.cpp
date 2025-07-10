#include <iostream>
using namespace std;

int power(int base, int exp)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}

void RabinKarp(auto txt[], auto pat[], int n, int m, int q, int b)
{
    int p = 0;
    int t = 0;
    int h = power(b, m - 1);
    for (int i = 0; i < m; i++)
    {
        p = (p * b + pat[i]) % q;
        t = (t * b + txt[i]) % q;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            int j = 0;
            for (j = 0; j < m; j++)
            {
                if (txt[i + j] != pat[j])
                    break;
            }
            if (j == m)
            {
                cout << "Pattern match" << endl;
                return;
            }
        }

        // Update hash
        if (i < n - m)
        {
            t = ((t - txt[i] * power(b, m - 1)) * b + txt[i + m]) % q;

            if (t < 0)
                t += q;
        }
    }

    cout << "Pattern not matched" << endl;
}

int main()
{
    int txt[] = {8, 6, 2, 1, 5, 4, 2, 6, 8};
    int pat[] = {1, 5, 4};

    int n = sizeof(txt) / sizeof(txt[0]);
    int m = sizeof(pat) / sizeof(pat[0]);
    int q = 101; // A prime number
    int b = 10;  // Base for hashing

    RabinKarp(txt, pat, n, m, q, b);

    return 0;
}