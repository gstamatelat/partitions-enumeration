/*
 * Algorithm Y.
 * 
 * Usage   : y <n> <k>
 * Example : y  5   3
 */
#include <iostream>
#include <cstdlib>

int next(int *a, int *b, int n, int k)
{
    int c = n - 1;
    while (a[c] == k - 1 || a[c] > b[c])
    {
        c = c - 1;
    }
    if (c == 0)
        return 0;
    a[c] = a[c] + 1;
    for (int i = c + 1; i < n; i++)
    {
        a[i] = 0;
        b[i] = std::max(a[i - 1], b[i - 1]);
    }
    if (std::max(a[n - 1], b[n - 1]) != k - 1)
    {
        for (int i = n - 1, k0 = k - 1; k0 > b[i]; i--, k0--)
        {
            a[i] = k0;
            b[i] = k0 - 1;
        }
    }
    return 1;
}

void first(int *a, int *b, int n, int k)
{
    for (int i = n - k; i < n; i++)
    {
        a[i] = i - n + k;
        b[i] = std::max(a[i - 1], b[i - 1]);
    }
}

int main(int argc, char *argv[])
{
    const int n = std::atoi(argv[1]);
    const int k = std::atoi(argv[2]);
    int *a = new int[n]();
    int *b = new int[n]();
    first(a, b, n, k);
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
        r = next(a, b, n, k);
    } while (r == 1);
    delete[] a;
    delete[] b;
}
