#include <stdlib.h>
#include <windows.h>
void f(int n)
{   int i;
    int t[100000];
    for (i=1;i<=n;i++) t[i]=i;

    for (i=1;i<=n;i++) t[i]=rand() % n;

}
