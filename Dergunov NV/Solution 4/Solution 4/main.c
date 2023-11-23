#include <stdio.h>
#define N 7
#include <locale.h>


void main() {
	setlocale(LC_ALL, "Rus");
	int sum = 0;
	int sum_discount = 0;
	int sum_with_discount = 0;
	int a[4];
	int b, c;
	int cnt = 0;
	double total_amount = 0;


	int code[N][4] = { {1,2,3,4}, {7,2,3,4}, {1,2,1,7}, {2,3,4,1}, {6,9,6,3}, {9,6,8,4}, {1,8,7,3} };
	char* product[N] = { "��������", "������", "��������", "�����", "���������", "������", "�����" };
	int price[N] = { 1000, 2500, 900, 1000, 5000, 1700, 2000 };
	int discount[N] = { 5, 35, 10, 20, 25, 15, 30 };
	int count[N] = { 0, 0, 0, 0, 0, 0, 0 };

	do {
		printf("������� �������� ������ (��� ������ ���� ������� 0):\n");
		scanf_s("%d", &b);
		c = b;
		for (int i = 3; i >= 0; i--) {
			a[i] = b % 10;
			b /= 10;
		}


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 4; j++) {
				if (a[j] == code[i][j]) {
					cnt += 1;
				}
			}
			if (cnt == 4) {
				count[i]++;
				printf("�����-���: %d | ������������: ", c);
				printf(product[i]);
				printf("  | ����: %d ������ | ������: %d %%\n", price[i], discount[i]);
			}
			cnt = 0;
		}
	} while (c != 0);


	for (int i = 0; i < N; i++) {
		sum += price[i] * count[i];
		sum_discount += price[i] * discount[i] / 100 * count[i];
		sum_with_discount += price[i] * (100 - discount[i]) / 100 * count[i];
	}
	printf("\n");
	printf("��� �����\n");
	printf("����� ���������:         \n");

	for (int i = 0; i < N; i++) {
		if (count[i] != 0) {
			printf(product[i]);
			printf(" | %d ������ | %d ��. | %d ������ \n", price[i], count[i], count[i] * price[i]);

		}
	}
	printf("�����: %d ������\n", sum);
	printf("������: %d ������\n", sum_discount);
	printf("� ������ : %d ������\n", sum_with_discount);
	printf("������� �� �������! ����� �������!\n");
}