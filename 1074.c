#include<stdio.h>
int calc(int x)
{
    int answer = 0;
    int n = 1;
    while(x) {
        if(x&1) answer += n*n;
        n <<= 1;
        x >>= 1;
    }
    return answer;
}

int main(void){
    int n, r, c;
    scanf("%d %d %d",&n,&r,&c);
    printf("%d",((calc(r)<<1)+calc(c)));
}