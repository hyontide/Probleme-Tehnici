#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *st, n;

void Afisare(int k)
{

	FILE *out = fopen("problema3.out", "a");
	int i = 1, j = 1;
	for(i = 1; i <= k; i++, printf("\n"))
		for(j = 1; j <= k; j++)
			if(j == st[i])
				printf("D");
			else
				printf("*");
	printf("\n");
	fclose(out);
}

int valid(int k)
{
	int i;
	for(i = 1; i <= k - 1; i++)
		if((st[i] == st[k]) || abs(st[k]- st[i]) == (k - i))
			return 0;
	return 1;
}

void bkt(int k)
{
	int i = 1;
	for(i = 1; i <= n; i++)
		{
			st[k] = i;
			if(valid(k))
				if(k == n)
					Afisare(k);
				else
					bkt(k + 1);
		}
}

void Citire()
{
	FILE *in = fopen("problema3.in", "r");
	st = (int*)malloc(sizeof(int) * n);
	fscanf(in, "%d", &n);
	free(in);
}

int main()
{
	Citire();
	bkt(1);
	free(st);
	return 0;
}