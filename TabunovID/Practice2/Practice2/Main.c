#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int a;

	printf("select game mode 1 or 2\n");
	scanf_s("%d", &a);

	if (a == 1) {
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
	}

	else if (a == 2) {

		int num_of_machine;
		int num;
		char znak;
		srand(time(NULL));
		num_of_machine = 1 + rand() % 1000;
		int counter = 0;
		int x = 0, y = 1000;

		printf("enter = , + , - \n");

		while (1 > 0) {
			printf("is this your number?\n");
			printf("%d", num_of_machine);
			scanf_s("%c", &znak);

			if (znak == '=') {
				printf("the robot guessed it, well done!");
				return 0;
			}

			if (znak == '-') {
				y = num_of_machine;
				num_of_machine = x + rand() % (1000 - y + 1);
			}

			if (znak == '+') {
				x = num_of_machine;
				num_of_machine = x + rand() % (1000 - y + 1);
			}

			counter++;
		}
	}

	else {
		printf("select game mode 1 or 2");
	}
	

	return 0;
}
