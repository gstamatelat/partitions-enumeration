/*
 * Algorithm V.
 * 
 * Usage   : v <n>
 * Example : v  5
 */
#include <iostream>
#include <cstdlib>

int next(int *a, int *b, int n)
{
    int c = n - 1;
    while (a[c] == n - 1 || a[c] > b[c])
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
    return 1;
}

int main(int argc, char *argv[])
{
    const int n = std::atoi(argv[1]);
    int *a = new int[n]();
    int *b = new int[n]();
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
        r = next(a, b, n);
    } while (r == 1);
    delete[] a;
    delete[] b;
}
