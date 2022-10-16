#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	char mode;
	do {
		printf("Choose game mode: \n1 - you guess number\n2 - you choose number \n");
		scanf("%c", &mode);
	} while (mode != '1' && mode != '2');

	if (mode == '1') {
		short try_count = 1, answer, cur_ans;
		srand((unsigned int)time(NULL));
		answer = rand() % 1000;

		printf("I chose the number. Try to guess it! (type '-11' for answer) \n");

		while (1) {
			printf("What's your guess? \n");
			scanf("%hd", &cur_ans);

			if (cur_ans == -11) {
				printf("%hd \n", answer);
			}
			else if (cur_ans < 0 || cur_ans > 1000) {
				printf("Wrong input. \n");
			}
			else if (cur_ans < answer) {

				printf("This number < than my number. Try again. (Tries: %hd) \n", try_count);
				try_count++;
			}
			else if (cur_ans > answer) {

				printf("This number > than my number. Try again. (Tries: %hd) \n", try_count);
				try_count++;
			}
			else if (cur_ans == answer) {
				printf("You're right! You've guessed my number in %hd tries. \n", try_count);
				return 0;
			}
		}

	}
	return 0;
}