#include <stdio.h>
#define N 7
int Scan_product(int a[], int kolichestvo[], int sch)
{
	int k;
	do
	{
		printf ("Vvedite shtrich-kod\n");
		scanf ("%d", &a[sch]);
	}
	while ((a[sch] > N) || (a[sch] < 1));
	printf ("Vvedite kolichestvo tovara\n");
    scanf ("%d", &k);
	return k;
}
void Product_description(char prod[][10], int stoimost[], int skidka[], int k)
{
	int i;
	for(i=0; i < 10; i++)
		printf ("%c", prod[k][i]);
	printf ("stoimost = %d, skidka = %d\n", stoimost[k], skidka[k]);
}
void Add_item_to_check(int kolichestvo[], int nom, int koltov)
{
	kolichestvo[nom] += koltov;
}
void Form_a_check(int prod[][10],int stoimost[],int skidka[],int kolichestvo[])
{
	int osbs = 0, ss = 0, m;
	for(m = 0; m < N; m++)
	{
		if ( kolichestvo[m] > 0)
		{
			Product_description(prod, stoimost, skidka, m);
		    printf ("Kolichestvo tovara = %d", kolichestvo[m]);
		    osbs = osbs + kolichestvo[m] * stoimost[m];
            ss += stoimost[m] * 0.01 * (100 - skidka[m] * kolichestvo[m]);
		}
	}
	printf("Stoimost bez skidok = %d\n Stoimost so skidkami = %d\n Obschaya skidka = %d\n", osbs, ss, (osbs - ss) * 100 / osbs);
}


void main()
{//baza
	char prod[N][10] = {"          ", "butter    ", "ice cream  ", "milk      ", "yogurt    ", "tea       ", "eggs      "};
	int stoimost[N] = {0, 70, 50, 50, 30, 80, 60};
	int skidka[N] = {0, 5, 5, 10, 5, 5, 3};
	int kolichestvo[N] = {0};
	int a[10];
	int vybor, kolvo, sch = 0; // kolvo tecushi tovar

	do
	{
		printf (" 1. Scan product \n 2. Product description \n 3. Add item to check \n 4. Form a check \n 5. Calculate the total  ");
		scanf ("%d", &vybor);
		switch (vybor)
		{
		case 1: Scan_product(a, kolichestvo, sch);
			break;
		case 2: Product_description(prod, stoimost, skidka, a[sch]);
			break;
		case 3: Add_item_to_check(kolichestvo, a[sch], kolvo);
			sch++;
			break;
		case 4: Form_a_check(prod, stoimost, skidka, kolichestvo);
			break;
		case 5: Form_a_check(prod, stoimost, skidka, kolichestvo);
			break;
		}
	}
	while (vybor!=5);
}