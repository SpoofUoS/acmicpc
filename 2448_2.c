#include<stdio.h>
#define MAX_X 3072
#define MAX_Y 6143

typedef char star[MAX_X][MAX_Y];

void alloc_star(char star[MAX_X][MAX_Y], int px, int py, int n)
{
    if (px <n)
    {
        star[px][py] = star[px+1][py-1] = star[px+1][py+1] = '*';
        for(int i = 0; i<5; i++)
        {
            star[px+2][py-2+i] = '*';
        }
        alloc_star(star[MAX_X][MAX_Y], px-3, py-3, n);
        alloc_star(star[MAX_X][MAX_Y], px-3, py+3, n);
    }
}


int main()
{
    char star[MAX_X][MAX_Y];
    int n, i, j;

    for (i=0;i<MAX_X;i++) {
        for (j=0;j<MAX_Y; j++) {
            star[i][j] = ' ';
        }
    }
    scanf("%d",&n);

    alloc_star(star, 0, n-1, 3);

    for(i=0;i<n;i++){
        for(j=0;j<(2*n-1);j++){
            printf("%c",star[i][j]);
        }
        printf("\n");
    }

}