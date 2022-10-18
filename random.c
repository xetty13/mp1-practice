#include <stdio.h>
#include <stdlib.h>

int main() {
	int num;
	int flag = 1;
	int counter = 0;
	int number_of_machine;
	
	srand(time(NULL));
	number_of_machine = 1 + rand() % 999;

	while (flag == 1) {
		printf("enter a number\n");
		scanf_s("%d", &num);

		if (num == number_of_machine) {
			printf("gg wp\n");
			printf("%d\n", num);
			printf("number of attempts:\n");
			printf("%d", counter);
			return 0;
		}

		if (num < number_of_machine) {
			printf("the number is bigger than what you wrote\n");
		}

		if (num > number_of_machine) {
			printf("the number is less then what you wrote\n");
		}

		counter++;
	}

	return 0;
}
