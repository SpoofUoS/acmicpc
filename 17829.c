#include<stdio.h>
#include<stdlib.h>
typedef short sh;

int cmpfunc (const void *a, const void *b) {return ( *(sh*)a - *(sh*)b );}

sh ttt_puling(sh a, sh b, sh c, sh d)
{
    sh arr[4] = {a, b, c, d};
    qsort(arr, 4, sizeof(sh), cmpfunc);
    return arr[2];
}

sh func(sh x, sh y, sh **matrix, sh n)
{
    sh answer;
    if(n == 2){
        return ttt_puling(matrix[x][y], matrix[x][y+1], matrix[x+1][y], matrix[x+1][y+1]);
    } else {
        sh a,b,c,d;
        a = func(x,y,matrix,n/2);
        b = func(x,y+n/2,matrix,n/2);
        c = func(x+n/2,y,matrix,n/2);
        d = func(x+n/2,y+n/2,matrix,n/2);
        answer = ttt_puling(a,b,c,d);
    }
    return answer;
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
    printf("%hd", func(0,0,matrix,n));

    for(int i = 0; i<n; i++) free(matrix[i]);
    free(matrix);
}