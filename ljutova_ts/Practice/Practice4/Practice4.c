#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define N 10 
#define K 10 
#define L 10 
#define M 10 
void fill_shtrih(int a[], int n)
{
	int i;
	{
		printf("Vvedite shtrih-cod 1 chislo: \n ");
		scanf("%d", &(a[i]));
		printf("Vvedite shtrih-cod 2 chislo: \n ");
		scanf("%d", &(a[i + 1]));
		printf("Vvedite shtrih-cod 3 chislo: \n ");
		scanf("%d", &(a[i + 2]));
		printf("Vvedite shtrih-cod 4 chislo: \n ");
		scanf("%d", &(a[i + 3]));
		return;
	}
}
void fill_name(char b[], int n)
{
	int j;
	for (j = 0; j < n; j++)
	{
		printf("Vvedite naimenovanie: ");
		scanf("%c", &(b[j]));
	}
}
void fill_stmst(int c[], int n)
{
	int s;
	srand((unsigned)time(0));
	for (s = 0; s < n; s++)
		c[s] = rand();
}
void fill_skidka(float d[], int n)
{
	int y;
	srand((unsigned)time(0));
	for (y = 1; y < n; y++)
		d[y] = 0.49 + rand();
}
int sum(int c[], int n)
{
	int sum, s;
	for (s = 0; s < n; s++)
		sum += c[s];
	return sum;

}
void output_shtrih(int a[], int n)
{
	int i;
	for (i = 0; i < 4; i++)
		printf("%d", a[i]);
}
void output(int a, int b, char c, float d)
{
	printf("Shtrih-cod: %d \n", a);
	printf("Naimenovanie: %d \n", b);
	printf("Stoimost: %c \n", sum);
	printf("Skidka: %.2f \n", d);

}
void main()
{
	int X[N], Y[K], Z[L], W[M];
	fill_shtrih(X, N);
	fill_name(Y, K);
	fill_stmst(Z, L);
	fill_skidka(W, M);
	output(X[N], Y[K], Z[L], W[M]);
	printf("%d", sum(X, N), (Y, K), (Z, L), (W, M));
}