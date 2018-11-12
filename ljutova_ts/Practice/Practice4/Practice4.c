#include <stdio.h>
#define N 10
#define K 10
#define L 10
#define M 10
void fill(int a[], int n)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		printf("Vvedite shtrih-cod: ");
		scanf("%d", &(a[i]));
	}
}
void fill(char b[], int n)
{
	int j;
	for (j = 0; j < n; j++)
	{
		printf("Vvedite naimenovanie: ");
		scanf("%c", &(b[j]));
	}
}
void fill(int c[], int n)
{
	int s;
	for (s = 0; s < n; s++)
	{
		printf("Vvedite stoimost' za edinitsy tovara: ");
		scanf("%d", &(c[s]));
	}
}
void fill(int d[], int n)
{
	int y;
	for (y = 0; y < n; y++)
	{
		printf("Vvedite skidky: ");
		scanf("%d", &(d[y]));
	}
}
void sum(int c[], int s)
{
	int s, n;
	for (s = 0; s < n; s++)
	{
		c[s] += c[s];
	}

}
void output(int a[], int n)
{
	int i;
	for (i = 0; i < 4; i++)
		printf( "%d", a[i]);
}
void output(int b[], int n)
{
	int j;
	for (j = 0; j < n; j++)
		printf("%c", b[j]);
}
void output(int c[], int n)
{
	int s;
	for (s = 0; s < n; s++)
		printf("%d", c[s]);
}
void output(int d[], int n)
{
	int y;
	for (y = 0; y < n; y++)
		printf("%c", d[y]);
}
