#include<stdio.h>
#include<stdlib.h>

void alloc_star(char **star, int n)
{
    for(int i = 0; i<n; i++){
        for(int j=n-1-i; j<=n-1+i; j++){
            star[i][j] = '*';
        }
    }

}

void delete_star(char **star, int x, int y, int n)
{
    if (n > 3)
    {
        int tmp;
        for (int i = n/2; i<n; i++)
        {
            tmp = n-i-1;
            for (int j = -tmp; j <= tmp; j++) star[i+x][j+y] = ' ';
        }
        delete_star(star, x, y, n/2);
        delete_star(star, x+n/2, y-n/2, n/2);
        delete_star(star, x+n/2, y+n/2, n/2);
    }
    else if (n == 3) {
        star[x+1][y] = ' ';
    }
}

int main()
{
    int n,i,j;
    scanf("%d",&n);

    char **star;
    star = (char **)malloc(sizeof(char*)*n);
    for(i=0;i<n;i++)
    {
        star[i] = (char *)malloc(sizeof(char) * 2*n-1);
    }

    for (i=0;i<n;i++) {
        for (j=0;j<2*n-1; j++) {
            star[i][j] = ' ';
        }
    }

    alloc_star(star, n);
    delete_star(star, 0, n-1, n);

    for(i=0; i<n; i++){
        for(j=0; j<2*n-1; j++){
            printf("%c",star[i][j]);
        }
        printf("\n");
    }


    for(i=0; i<n; i++)
    {
        free(star[i]);
    }
    free(star);
}