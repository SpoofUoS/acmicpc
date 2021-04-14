#include<stdio.h>
#include<stdlib.h>
typedef short sh;
int n_1 = 0;
int n_0 = 0;
int n__1 = 0;

sh is_same(sh p[9])
{
    for(int i = 0; i<8; i++)
    {
        if (p[i] != p[i+1]) return 0;
    }
    return 1;
}

sh cut_paper(sh **paper, int x, int y, int n) // 종이, x좌표, y좌표, 비교할 종이의 크기
{
    if (n == 1) return paper[x][y];

    /*
        1 2 3       나눌 종이의 번호
        4 5 6
        7 8 9
    */
    else {

    sh p[9];

    p[0] = cut_paper(paper, x, y, n/3);                // 1
    p[1] = cut_paper(paper, x, y+n/3, n/3);            // 2
    p[2] = cut_paper(paper, x, y+2*n/3, n/3);          // 3
    p[3] = cut_paper(paper, x+n/3, y, n/3);            // 4
    p[4] = cut_paper(paper, x+n/3, y+n/3, n/3);        // 5
    p[5] = cut_paper(paper, x+n/3, y+2*n/3, n/3);      // 6
    p[6] = cut_paper(paper, x+2*n/3, y, n/3);          // 7
    p[7] = cut_paper(paper, x+2*n/3, y+n/3, n/3);      // 8
    p[8] = cut_paper(paper, x+2*n/3, y+2*n/3, n/3);    // 9

    if(is_same(p)) return p[0];
    else {
        for(int i=0; i<9; i++) {
            if (p[i] == 1) n_1 += 1;
            else if (p[i] == 0) n_0 += 1;
            else if (p[i] == -1) n__1 += 1;
        }
        return 2;
    }
    }
}

int main(void)
{
    int n, x, i, j;
    scanf("%d",&n);

    sh **paper;
    paper = (sh **)malloc(sizeof(sh*)*n);

    for(i=0;i<n;i++) {
        paper[i] = (sh *)malloc(sizeof(sh)*n);
        for(j=0;j<n;j++) scanf("%d",&paper[i][j]);
    }

    x = cut_paper(paper, 0, 0, n);

    if (x == 2) printf("%d\n%d\n%d",n__1,n_0,n_1);
    else {
        if (x == 1) printf("0\n0\n1");
        else if (x == 0) printf("0\n1\n0");
        else printf("1\n0\n0");
    }
}