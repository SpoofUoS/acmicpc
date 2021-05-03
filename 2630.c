#include<stdio.h>
#include<stdlib.h>

typedef short sh;
int white = 0;
int blue = 0;

sh func(sh x, sh y, sh** matrix, sh n)
{
    if (n==1) return matrix[x][y];
    else {
        sh a, b, c, d;
        a = func(x, y, matrix, n/2);
        b = func(x, y+n/2, matrix, n/2);
        c = func(x+n/2, y, matrix, n/2);
        d = func(x+n/2, y+n/2, matrix, n/2);
        if (a==b && b==c && c==d) {
            return a;
        }
        else {
            if (a==0) white++; else if (a==1) blue++;
            if (b==0) white++; else if (b==1) blue++;
            if (c==0) white++; else if (c==1) blue++;
            if (d==0) white++; else if (d==1) blue++;
            return 2;
        }
    }
}

int main()
{
    sh n;
    scanf("%hd", &n);
    sh **matrix;
    matrix = (sh **)malloc(sizeof(sh *)*n);
    for(int i = 0; i<n; i++) {
        matrix[i] = (sh *)malloc(sizeof(sh)*n);
        for(int j=0;j<n;j++){
            scanf("%hd", &matrix[i][j]);
        }
    }
    sh a;
    a = func(0,0,matrix, n);
    if (a==0) white++; else if (a==1) blue++;
    printf("%d\n%d",white, blue);
}