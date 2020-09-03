/*
 * Algorithm U.
 * 
 * Usage   : u <n> <k1> <k2> <k3>
 * Example : u  5   1    2    4
 */
#include <iostream>
#include <cstdlib>
#include <algorithm>

int next(int *a, int *b, int *k, int *m, int n, int ksize)
{
    /* Find which index to increment going backwards */
    int i = n;
    int tmpMax;
    do
    {
        i--;
        tmpMax = std::max(a[i] + 1, b[i]);
    } while (i > 0 && (a[i] == k[ksize - 1] - 1 || m[tmpMax + 1] - tmpMax - 1 > n - i - 1 || a[i] > b[i]));
    if (i == 0)
        return 0;
    a[i]++;
    b[i + 1] = std::max(a[i], b[i]);

    /* Start going forward putting zeroes for as long as we can */
    int zeroes = b[i + 1] + n - i - m[b[i + 1] + 1];
    for (i = i + 1; zeroes > 0 && i < n; i++, zeroes--)
    {
        a[i] = 0;
        b[i + 1] = b[i];
    }

    /* Keep going forward putting the minimum values that we can */
    for (; i < n; i++)
    {
        a[i] = b[i] + 1;
        b[i + 1] = a[i];
    }

    /* Return */
    return 1;
}

void first(int *a, int *b, int *k, int *m, int n, int ksize)
{
    std::sort(k, k + ksize);
    for (int i = n - 1; i > n - k[0]; i--)
    {
        a[i] = k[0] - n + i;
        b[i] = k[0] - n + i - 1;
    }
    int c = 0;
    for (int i = 0; i < ksize; i++)
    {
        for (; c < k[i] + 1; c++)
        {
            m[c] = k[i];
        }
    }
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
    first(a, b, k, m, n, ksize);
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
        r = next(a, b, k, m, n, ksize);
    } while (r == 1);
    delete[] a;
    delete[] b;
    delete[] m;
}
