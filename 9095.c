#include<stdio.h>
int a[11] = {1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274};
int main()
{
	int t, n;
	scanf("%d", &t);
	for(int i = 0; i<t; i++)
	{
		scanf("%d", &n);
		printf("%d\n", a[n]);
	}
}

// a[0] = 1, a[1] = 1, a[2] = 2   a[i] = a[i-1] + a[i-1] + a[i-3]