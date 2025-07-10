#include <iostream>
using namespace std;

void prefixTable(char P[], char T[], int pt[], int n, int m)
{
    int j = 0;
    pt[0] = 0;
    int i = 1;

    while (i < m)
    {
        if (P[j] == P[i])
        {
            j++;
            pt[i] = j;
            i++;
        }
        else
        {
            if (j != 0)
            {
                j = pt[j - 1];
            }
            else
            {
                pt[i] = 0;
                i++;
            }
        }
    }
}

void KMP(char P[], char T[], int pt[], int n, int m)
{
    prefixTable(P, T, pt, n, m);
    int i = 0, j = 0;

    while ((n - i) > (m - j))
    {
        if (T[i] == P[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            cout << "Pattern match" << endl;
            break;
        }
        else
        {
            if (i < n && P[j] != T[i])
            {
                if (j != 0)
                {
                    j = pt[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
    }
}

int main()
{

    char T[] = "bacbababababacaca";
    char P[] = "ababaca";
    int n = sizeof(T) - 1;
    int m = sizeof(P) - 1;

    int pt[m];
    KMP(P, T, pt, n, m);

    return 0;
}