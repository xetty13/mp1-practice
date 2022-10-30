#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define N 5




int unique_number()
{
	int l, i, n = 0,q=9.9, multi, k, j, m[N], p = 0, unique = 1, old_n,mass[N];
	printf("Input length of riddled number: \n");
	do {
		scanf("%d", &l);
	} while (l < 2 || l > 5);
	do {
		for (i = 2, q = 9.9, multi = 10; i <= 5; i++, multi *= 10) {
			if (l == i) {
				n = multi + rand() % (q * multi - multi + 1);
				break;
			}
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

int Shchitar_of_cows_and_bulls(int pc_n, int user_n) {
	int k, pc_mass[N], m_pc[N], i = 0, j, m_user[N], cows = 0, bulls = 0, user_mass[N], k1;
	while (pc_n != 0 && user_n != 0) {
		k = pc_n % 10;
		k1 = user_n % 10;
		pc_mass[i] = k;
		user_mass[i] = k1;
		user_n = user_n / 10;
		pc_n = pc_n / 10;
		i++;
	}
	for (i = 0; i < N; i++) {
		m_pc[i] = pc_mass[i];
		m_user[i] = user_mass[i];
	}
	for (i = 0, j = 4; i < 5; i++) {
		pc_mass[i] = m_pc[j];
		user_mass[i] = m_user[j];
		j = j - 1;
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (pc_mass[i] < 0 && user_mass[j] < 0) {
				break;
			}
			if (user_mass[j] == pc_mass[i] && j == i) {
				cows += 1;
			}
			if ((user_mass[j]== pc_mass[i]) && j != i){
				bulls += 1;
			}
		}
	}
	printf("%d ", cows);
	printf("%d", bulls);
	return cows, bulls;
}

int main() {
	srand(time(NULL));
	int pc_n,user_n,cows1=0,bulls=0;
	pc_n = unique_number();
	printf("Computer`s number: %d\n", pc_n);
	user_n = unique_number();
	printf("User number: %d\n", user_n);
	printf("\n");
	cows1,bulls= Shchitar_of_cows_and_bulls(pc_n, user_n);
	printf("Cows count: %d\n", cows1);
	printf("Bulls count: %d\n", bulls);
	return 0;
}



