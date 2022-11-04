#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define N 5




int unique_number()
{
	int l, i, n = 0,q=9.9, multi, k, j, m[N], p = 0, unique = 1, old_n,mass[N],digit;
	printf("Input length of riddled number: \n");
	do {
		scanf("%d", &l);
	} while (l < 2 || l > 5);
	do {
		for (i = 1; i <= l; i++) {
			digit = 0 + rand() % (9 - 0 + 1);
			n = 10 * n + digit;
		}
		old_n = n;
		i = 0;
		while (n != 0) {
			k = n % 10;
			mass[i] = k;
			if (mass[i] < 0) {
				mass[i] = 0;
			}
			n = n / 10;
			i++;
		}
		for(i = 0; i < N; i++) {
			if (mass[i] < 0) {
				mass[i] = 0;
			}
		}
		for (i = 0; i < N; i++) {
			m[i] = mass[i];
		}
		for (i = 0, j = 4; i < 5; i++) {
			mass[i] = m[j];
			j = j - 1;
		}
		unique = 1;
		for (i = 0; i < N; i++) {
			for (j = i + 1; j < N; j++) {
				if (mass[i] == 0) { //Iskluchenie nuley
					break;
				}
				else if (mass[i] == mass[j]) {
					unique = 0;
					break;
				}
			}
			if (unique == 0) {
				for (i = 0; i < N; i++) {
					mass[i] = 0;
				}
				break;
			}
		}
	} while (unique == 0);
	printf("\n");

	for (i = 0; i < N; i++) {
		p = 10 * p + mass[i];
	}
	return p;
}

int main() {
	srand(time(NULL));
	int pc_n,user_n,cows=0,bulls=0, k, pc_mass[N], m_pc[N], i = 0, j, m_user[N], user_mass[N], k1,signal=1,kolvo=0,saved_pc_n,flag=0,i_saved=0,mark1=0,significanse=2,id=0;		
	pc_n = unique_number();
	printf("PC %d\n", pc_n);
	do{ //*pobedniy do...while
		do{ //* unikalnost chisla
			printf("Input unique number: ");
			scanf_s("%d", &user_n);
			printf("\n");
			i = 0;
			saved_pc_n = pc_n;
			kolvo = 0;
			while (pc_n != 0 && user_n != 0) {
				k = pc_n % 10;
				k1 = user_n % 10;
				pc_mass[i] = k;
				user_mass[i] = k1;
				user_n = user_n / 10;
				pc_n = pc_n / 10;
				i++;
				kolvo++;
				if ((pc_n != 0 && user_n == 0) || (pc_n == 0 && user_n != 0)) {
					printf("Game exited with error 1");
					return 1;
				}
			}
			pc_n = saved_pc_n;
			for (i = 0; i < N; i++) {
				m_pc[i] = pc_mass[i];
				m_user[i] = user_mass[i];
			}
			for (i = 0, j = 4; i < 5; i++) {
				pc_mass[i] = m_pc[j];
				user_mass[i] = m_user[j];
				j = j - 1;
			}
			signal = 1;
			for (i = 0; i < N; i++) {
				for (j = i + 1; j < N; j++) {
					if (user_mass[i] <= 0) {
						break;
					}
					else if (user_mass[i] == user_mass[j]) {
						signal = 0;
						break;
					}
				}
				if (signal == 0) {
					for (i = 0; i < N; i++) {
						user_mass[i] = 0;
					}
					break;
				}
			}
		} while (signal == 0);
		flag = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if ((pc_mass[i] <= 0 && user_mass[j] <= 0 && (i == 0 && j == 0 || i == 1 && j==0 || i==2 && j==-0))) {
					if (flag == 0) {
						break;
					}
				}
				if (pc_mass[i] >= 0 && user_mass[j] <= 0) {
					if (flag == 0) {
						j = i;
						i_saved = j;
						flag = 1;
					}
					if (mark1 == 0) {
						j = i_saved;
						mark1 = 1;
					}
				}
				if (user_mass[j] == pc_mass[i] && j == i) {
					bulls += 1;
				}
				if ((user_mass[j] == pc_mass[i]) && j != i) {
					cows += 1;
				}
			}
			mark1 = 0;
		}
		printf("Cows count: %d\n", cows);
		printf("Bulls count: %d\n", bulls);
		if (bulls != kolvo) {
			cows = 0;
			bulls = 0;
			for (i = 0; i < N; i++) {
				user_mass[i] = 0;
			}
			for (i = 0; i < N; i++) {
				pc_mass[i] = 0;
			}
		}
	} while (bulls != kolvo);
	printf("Congratulations! You won!");
	return 0;
}



