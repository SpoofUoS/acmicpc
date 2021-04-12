#include<stdio.h>

int num = 1;

void alloc_star(char star[][], int px, int py)
{
    star[px][py] = star[px+1][py-1] = star[px+1][py+1] = '*';
    for(int i = 0; i<5; i++)
    {
        star[px+2][py-2+i] = '*';
    }
}

int main()
{
    int n,i,j;

    scanf("%d",&n);

    char star[n][2*n-1];

    num = 2*n-1;

    for(i=0;i<n;i++){
        for(j=0;j<2*n-1; j++) {
            star[i][j] = ' ';
        }
    }

    if (n == 3) alloc_star(star[][num], 2, 0);

    /*
    for(i=0;i<n;i += 3){
        for(j=0;j<2*n-1; j++) {
            star[i][j] = ' ';
        }
    }
    */



    for(i=0;i<n;i++){
        for(j=0;j<2*n-1; j++) {
            printf("%c", star[i][j]);
        }
        printf("\n");
    }

}