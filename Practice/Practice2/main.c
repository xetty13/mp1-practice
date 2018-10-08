#include <stdio.h>
#include <stdlib.h>
#include < math.h > 
#include <locale.h>

int voz(int x)
{
  int k,c;
  c=1;
  for (k=0;k<x;k++)
  {
	  c*=10;
  }
  return(c);
}
int chisl(int x, int y)
{
	int k;
	k=x/voz(y-1)%10;
	return(k);
}
void main()
{
	int a,n,b,i,c;
	setlocale(LC_ALL, "Russian");
	scanf("%d", &n);
	scanf("%d",b);
	for (i=0;i<n;i++)
	{
		if (chisl(a, i)=chisl(b, i))
		{
			printf("%d", i);
		}
	}
}