/*
 * Algorithm Z*.
 * 
 * Usage   : z* <n> <kmin> <kmax>
 * Example : z*  5   2      3
 */
#include <iostream>
#include <cstdlib>

int next(int *a, int *b, int n, int kmin, int kmax)
{
    /* Find which index to decrement going backwards */
    int i = n - 1;
    while (i > 0 && (a[i] == 0 || kmin - b[i] > n - i))
    {
        i = i - 1;
    }
    if (i == 0)
        return 0;
    a[i] = a[i] - 1;
    b[i + 1] = std::max(a[i], b[i]);

    /* Start going forward putting the maximum possible values */
    for (i = i + 1; b[i] < kmax - 1 && i < n; i++)
    {
        a[i] = b[i] + 1;
        b[i + 1] = a[i];
    }

    /* Keep going forward putting kmax - 1 */
    for (; i < n; i++)
    {
        a[i] = kmax - 1;
        b[i + 1] = kmax - 1;
    }

    /* Return */
    return 1;
}

void first(int *a, int *b, int n, int kmin, int kmax)
{
    for (int i = 1; i < n; i++)
    {
        a[i] = std::min(i, kmax - 1);
        b[i] = a[i - 1];
    }
}

int main(int argc, char *argv[])
{
    const int n = std::atoi(argv[1]);
    const int kmin = std::atoi(argv[2]);
    const int kmax = std::atoi(argv[3]);
    int *a = new int[n]();
    int *b = new int[n + 1]();
    first(a, b, n, kmin, kmax);
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
        r = next(a, b, n, kmin, kmax);
    } while (r == 1);
    delete[] a;
    delete[] b;
}
