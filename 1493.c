#include<stdio.h>

typedef long long ll;

int main()
{
    int i, n, x, y;
    ll a, b, c;
    ll used;
    scanf("%ld %ld %ld", &a, &b, &c);

    ll box[20] = {};  // 필요한 상자
    ll box2[20] = {}; // 가지고 있는 상자

    int size = 0; // 연산 단위
    ll tmp;
    while(a && b && c){
        tmp = 0;

        if (a&1) tmp |= 1;
        if (b&1) tmp |= 2;
        if (c&1) tmp |= 4;

        switch (tmp)
        {
        case 0: size++; break;
        case 1: box[size++] = b*c; break;
        case 2: box[size++] = c*a; break;
        case 3: box[size++] = c*(a+b-1); break;
        case 4: box[size++] = a*b; break;
        case 5: box[size++] = b*(c+a-1); break;
        case 6: box[size++] = a*(b+c-1); break;
        case 7: box[size++] = a*b+b*c+c*a-a-b-c+1; break;
        }
        a >>= 1;
        b >>= 1;
        c >>= 1;
    }

    scanf("%d",&n);
    for(i = 0; i<n; i++){
        scanf("%ld %ld", &x, &y);
        box2[x] = y;
    }

    used = 0;
    for(i=19; i>0; i--){
        tmp = box2[i] - box[i];
        if (tmp < 0) {
            box[i-1] -= 8*tmp;
            used += box2[i];
        }
        else used += box[i];
    }

    if(box[0]>box2[0]) printf("-1");
    else printf("%ld",used + box[0]);
}
