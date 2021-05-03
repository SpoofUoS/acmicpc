#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void *a, const void *b) {return ( *(int*)a - *(int*)b );}

int main()
{
    int n, m, i;
    scanf("%d %d",&n,&m);
    int a[n+m];
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=n;i<n+m;i++) scanf("%d",&a[i]);
    qsort(a, n+m, sizeof(int), cmpfunc);
    for(int i=0;i<n+m;i++) printf("%d ",a[i]);
}