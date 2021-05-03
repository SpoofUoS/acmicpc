#include<stdio.h>
#include<stdlib.h>

int matrix[2][5][5] = {}; // matrix[0] 처음 주어지는 정보, matrix[1]은 계산을 저장할 배열

void calc (int x, int n)
{
    int temp_matrix[5][5] = {};
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                temp_matrix[i][j] += (matrix[1][i+k][j]*matrix[1][i][j+k]);
            }
        }
    }
    if(x)
    {
        int temp_matrix2[5][5] = {};
        for (int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    temp_matrix2[i][j] += (temp_matrix[i+k][j]*matrix[0][i][j+k]);
                }
            }
        }
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) matrix[1][i][j] = temp_matrix2[i][j] % 1000;
        return;
    }
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) matrix[1][i][j] = temp_matrix[i][j] % 1000;
}

void f(int n, int b)
{
    if (b==1) for(int i=0;i<n;i++) for(int j=0;j<n;j++) matrix[1][i][j] = matrix[0][i][j];
    else {
        if (b&1) calc(1, n);
        else calc(0, n);
        f(n, b/2);
    }
}

int main()
{
    int n, b;
    scanf("%d %d", &n, &b);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d", &matrix[0][i][j]);
    f(n,b);
    for(int i=0;i<n;i++) {for(int j=0;j<n;j++) printf("%d ",&matrix[1][i][j]); printf("\n");}
    return 0;
}