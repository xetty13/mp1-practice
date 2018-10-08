#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

void main() {
	long int n, Num1, Num2, cached_Num2, cached_2_Num2;
	int bufs, cows, cNum2;
	char current_number, comparing_number, flag = 0, flag2 = 0;
	setlocale(LC_ALL, "Russian");
	do {
		system("cls");
		printf("Игра \"БЫКИ И КОРОВЫ\"\n");
		printf("Введите длину загадываемого числа: ");
		scanf("%d", &n);
	} while (n <= 0);

	/*                           *
	 * загадывание числа сделать *
	 *                           */

	printf("Отлично, я загадал %d-значное число с неповторяющимися цифрами. Теперь попробуйте угадать его.\nВведите %d-значное число: ", n, n);
	while (1) {
		scanf("%d", &Num2);
		cNum2 = 0;
		cached_Num2 = Num2;
		while (cached_Num2 > 0) {
			cNum2++;
			cached_Num2 /= 10;
		}
		if (cNum2 == n) {
			cached_Num2 = Num2;
			while (cached_Num2 > 0) {
				current_number = cached_Num2 % 10;
				cached_2_Num2 = Num2;
				cached_Num2 /= 10;
				cached_2_Num2 = cached_Num2;
				while (cached_2_Num2 > 0) {
					comparing_number = cached_2_Num2 % 10;
					cached_2_Num2 /= 10;
					if (comparing_number == current_number) {
						flag++;
					}
				}
				if (flag) {
					flag2 = 0;
					if(flag2++ == 0) printf("Цифры в вашем числе повторяются. Повторите попытку: ");
					break;
				}
				else break;
			}
			//break;
			printf("gg");
			if (flag == 0) break;
		}
		else 
			printf("\aВы ввели не %d-значное число. Попробуйте еще раз: ", n);
	}


	printf("hello\n");

}