#include<stdio.h>

void cut(char arr[], int start, int end)
{
    if (end-start<3) return;
    int cut_start = (2*start+end)/3;
    int cut_end = (start+2*end)/3;
    for(int i = cut_start; i<cut_end; i++)
    {
        arr[i] = ' ';
    }
    cut(arr, start, cut_start);
    cut(arr, cut_end, end);
}

void get_cut(int n)
{
    int i;
    int N = 1;

    for (i=0;i<n;i++) N *= 3;

    char arr[N];

    for (i = 0; i<N; i++) arr[i] = '-';

    cut(arr,0, N);

    for (i = 0; i<N; i++) printf("%c", arr[i]);

    printf("\n");
}

int main() {
    int x;
    while (scanf("%d", &x) != EOF) {
        get_cut(x);
    }
    return 0;
}