#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 void main()
{
	int rezhim, n, a, b, n1 = 1, n2 = 1001, p = 0;
	char vvod;
	printf ("Ugadai chislo \n");
	srand ((unsigned int) time(0));
	printf ("Vybery rezhim 1 ili 2 \n");
	scanf ("%d", &rezhim);
	
	if (rezhim == 1)
	{ 
		n = 1000.0 / RAND_MAX * rand() + 1;
		do
		{
			printf ("Vvedite predpolagaemoe chislo \n");
		    scanf ("%d", &a);
		    if (a > n)
			{
				printf ("< \n");
			}
			if (a < n)
			{
				printf ("> \n");
			}
			p++;
		}
		while (a != n);
		{
			printf ("Vy otgadali \n");
			printf ("Chislo popytok = %d", p);
		}
	}
	if (rezhim == 2)
	{
		do
		{
			printf ("Zagadaite chislo \n");
			scanf ("%d", &b);
		}
		while ((b > 1000) || (b < 0));
		do
		{
			n = ((double) (n2 - n1)) / RAND_MAX * rand() + n1;
			printf ("Komputer predpolagaet chto eto %d \n", n);
			printf ("Vvedite podskazku \n");
			scanf ("%*c%c", &vvod);
				switch (vvod) 
				{
				case '>':
					n1 = n;
					break;
				case '<':
					n2 = n;
					break;
				case '=':
					break;
				}
				p++;
		}
		while(n!=b);
			printf ("Komputer vyigral \n");
			printf ("Chislo popytok = %d", p);
	}
 }