/*
 * Algorithm U*.
 * 
 * Usage   : u* <n> <k1> <k2> <k3>
 * Example : u*  5   1    2    4
 */
#include <iostream>
#include <cstdlib>
#include <algorithm>

int next(int *a, int *b, int *k, int *m, int *mr, int n, int ksize)
{
    /* Find which index to decrement going backwards */
    int i = n;
    int tmpMax;
    do
    {
        i--;
        tmpMax = std::max(a[i] - 1, b[i]);
    } while (i > 0 && (a[i] == 0 || m[tmpMax + 1] - tmpMax - 1 > n - i - 1));
    if (i == 0)
        return 0;
    a[i]--;
    b[i + 1] = std::max(a[i], b[i]);

    /* Switch direction and place the maximum values possible */
    int maxPossible = b[i + 1] + n - i;
    int kmax = maxPossible >= k[ksize - 1] ? k[ksize - 1] : mr[maxPossible];
    for (i = i + 1; b[i] < kmax - 1 && i < n; i++)
    {
        a[i] = b[i] + 1;
        b[i + 1] = a[i];
    }

    /* Maintain direction and fill the remaining places with kmax-1 */
    for (; i < n; i++)
    {
        a[i] = kmax - 1;
        b[i + 1] = kmax - 1;
    }

    /* Return */
    return 1;
}

void first(int *a, int *b, int *k, int *m, int *mr, int n, int ksize)
{
    std::sort(k, k + ksize);
    for (int i = 0; i < n; i++)
    {
        a[i] = std::min(i, k[ksize - 1] - 1);
        b[i + 1] = a[i];
    }
    int c = 0;
    for (int i = 0; i < ksize; i++)
    {
        for (; c < k[i] + 1; c++)
        {
            m[c] = k[i];
        }
    }
    for (int i = 0; i < ksize - 1; i++)
    {
        for (int j = k[i]; j < k[i + 1]; j++)
        {
            mr[j] = k[i];
        }
    }
    mr[k[ksize - 1]] = k[ksize - 1];
}

int main(int argc, char *argv[])
{
    const int n = std::atoi(argv[1]);
    const int ksize = argc - 2;
    int *k = new int[ksize];
    for (int i = 0; i < ksize; i++)
    {
        k[i] = std::atoi(argv[i + 2]);
    }
    int *a = new int[n]();
    int *b = new int[n + 1]();
    int *m = new int[n + 1]();
    int *mr = new int[n + 1]();
    first(a, b, k, m, mr, n, ksize);
    int counter = 1;
    int r;
    do
    {
        std::cout << counter++ << " ";
        for (int i = 0; i < n; i++)
        {
            std::cout << a[i];
        }
        std::cout << std::endl;
        r = next(a, b, k, m, mr, n, ksize);
    } while (r == 1);
    delete[] a;
    delete[] b;
    delete[] m;
}
