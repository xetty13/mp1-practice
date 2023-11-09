#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
int main()
{
	int n, bulls, cows, x, b;
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int number[5]; 
	int attempt[5]; 
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	printf("������� ����� n - ��� ����� (�� 2 �� 5):\n");
	scanf_s("%d", &n);
	x = 0 + rand() % 9;
	number[0] = a[x];
	a[x] = 999;
	for (int i = 1; i < n; i++)
	{
		x = 0 + rand() % 10;
		if (a[x] != 999)
		{
			number[i] = a[x];
			a[x] = 999;
		}
		else {
			while (a[x] == 999)
			{
				x = 0 + rand() % 10;
			}
			number[i] = a[x];
			a[x] = 999;
		}
	}
	do {
		bulls = cows = 0;
		printf("�������� ����� ������ n (� ������ ������� ��������� ����, �������� 0)\n");
		scanf_s("%d", &b);
		if (b == 0)
		{
			printf("���� ��������! �������, ����� �������!");
			break;
			return 0;
		}
		for (int i = n - 1; i >= 0; i--)
		{
			x = b % 10;
			attempt[i] = x;
			b = b / 10;
		}


		for (int i = 0; i < n; i++)
		{
			if (number[i] == attempt[i])
			{
				bulls++;
			}
			for (int j = 0; j < n; j++)
			{
				if (number[i] == attempt[j])
				{
					cows++;
				}
			}
		}
		cows = cows - bulls;
		printf("���������� �����: %d\n", cows);
		printf("���������� �����: %d\n", bulls);
		if (bulls == n) {
			printf("�� �������! �������!\n");
		}
	} while (bulls != n);

	return 0;
}