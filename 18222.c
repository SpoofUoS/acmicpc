#include<stdio.h>

typedef unsigned long long ll;

int calc(ll k)
{
    ll a = 0;
    while (k)
    {
        if (k&1) a++;
        k >>= 1;
    }
    if (a&1) return 1;
    else return 0;

}

int main()
{
    ll k;
    scanf("%lld", &k);
    printf("%d",calc(k-1));  
}