#include <stdio.h>
#include <stdlib.h>
#include < math.h > 
#include <locale.h>
#include <time.h>
int voz(int x)
{
  int e,c;
  c=1;
  for (e=0;e<x;e++)
  {
	  c*=10;
  }
  return(c);
}
int chisl(int x, int y)
{
	int k;
	k=(x/voz(y-1))%10;
	return(k);
}
void main()
{
	int a,n,i,h,k;
	int A[10]={0,0,0,0,0,0,0,0,0,0};
	int B[10]={0};
	setlocale(LC_ALL, "Russian");
	scanf("%d", &n);
	a=4444;
	printf("%d",a);
	
	while(1){
	scanf(" %d",&h);
	for (i=0; i<n; i++)
	{
			if (chisl(a,i)==chisl(h,i))
			{
				A[chisl(a,i)-1]+=1;
			}
		for (k=0; k<n; k++)
		{
			if (chisl(a,i)==chisl(h,k) && (i!=k))
			{
				B[chisl(a,i)-1]+=1;
			}
		}
	}
	printf("Быки: ");
	for (i=0; i<n; i++)
	{
		if (A[i]!=0) printf(" %d ",A[i]);
	}
	printf("Коровы: ");
	for (i=0; i<n; i++)
	{
		if (B[i]!=0) printf(" %d ",B[i]);
	}
	}
}