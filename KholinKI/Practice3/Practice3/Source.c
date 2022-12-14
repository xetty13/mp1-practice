#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define N 5




int unique_number()
{
	int l, i, n = 0, p = 0,mass[N],digit,g,count=0;
	printf("Input length of riddled number: \n");
	do {
		scanf("%d", &l);
	} while (l < 2 || l > 5);
		for (i = 0; i < l; i++) {
			digit = 0 + rand() % (9 - 0 + 1);		//generator sifr
			mass[i] = digit;
			for (g = 0; g < l; g++) {
				if (mass[i] == mass[g]) {
					count += 1;
				}
				if (count >= 2) {
					digit = 0 + rand() % (9 - 0 + 1);
					mass[i] = digit;
					count = 0;
					g = -1;
				}
			}
			count = 0;
		}
		i = 0;
		for(i = 0; i < N; i++) {
			if (mass[i] < 0) {	//ochistka musora
				mass[i] = 0;
			}
		}
	printf("\n");
	for (i = 0; i < N; i++) {
		//preobrazovanie massiva v chislo
		if (mass[i] == 0) {
			i = i;
		}
		else
		p = 10 * p + mass[i];
	}
		return p;
}

int main() {
	srand(time(NULL));
	int pc_n,user_n,cows=0,bulls=0, k, pc_mass[N], m_pc[N], m_user[N], user_mass[N]; //aux_arrays and arrays_work		
	int i = 0, j,kolvo=0; //counters
	int signal = 1, mark1 = 0, flag = 0, significanse = 2; // marks and signals;
	int k1, id = 0; //arithmetic vars
	int saved_pc_n, i_saved = 0; //saved vars
	pc_n = unique_number();
	printf("%d\n", pc_n);
	do{ //
		do{ //* unikalnost chisla
			printf("Input unique number: \n");
			scanf_s("%d", &user_n);	//polzovatel vvodit chislo
			printf("\n");
			i = 0;
			saved_pc_n = pc_n; // soxranenie chisla kompuktera
			kolvo = 0; //soxranenie dlini chisla
			while (pc_n != 0 && user_n != 0) {
				k = pc_n % 10;
				k1 = user_n % 10;
				pc_mass[i] = k;
				user_mass[i] = k1;			// pomechenie sift polzovatela i kompuktera v massivi
				user_n = user_n / 10;
				pc_n = pc_n / 10;
				i++;
				kolvo++;
				if ((pc_n != 0 && user_n == 0) || (pc_n == 0 && user_n != 0)) {
					printf("Game exited with error 1");
					return 1;
				}
			}
			pc_n = saved_pc_n; //soxranennoe chislo kompuktera vosstanavlivau
			for (i = 0; i < N; i++) {
				m_pc[i] = pc_mass[i];
				m_user[i] = user_mass[i];	//vvodim vspomogatelnie massivi
			}
			for (i = 0, j = 4; i < 5; i++) {
				pc_mass[i] = m_pc[j];
				user_mass[i] = m_user[j];	//perevorot massivov
				j = j - 1;
			}
			signal = 1;													//||||
			for (i = 0; i < N; i++) {
				for (j = i + 1; j < N; j++) {
					if (user_mass[i] <= 0) {
						break;
					}
					else if (user_mass[i] == user_mass[j]) {	
						signal = 0;
						break;
					}															//proverka unikalnosti chisla polzovatela
				}
				if (signal == 0) {
					for (i = 0; i < N; i++) {
						user_mass[i] = 0;
						m_pc[i] = 0;
						m_user[i] = 0;
						pc_mass[i] = 0;
					}
					break;
				}
			}
		} while (signal == 0);											//||||
		flag = 0;
		for (i = 0; i < N; i++) {															//|||||||||||||||||||||||||||
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
				}																		//METHOD KHOLIN: Avoiding nulls
				if ((user_mass[j] == pc_mass[i]) && j != i) {
					cows += 1;
				}
			}
			mark1 = 0;
		}																					//|||||||||||||||||||||||||||
		printf("Cows count: %d\n", cows);
		printf("Bulls count: %d\n", bulls);
		if (bulls != kolvo) {
			cows = 0;
			bulls = 0;
			for (i = 0; i < N; i++) {
				user_mass[i] = 0;
			}																//Podvedenit itogov i umivanie ruk
			for (i = 0; i < N; i++) {
				pc_mass[i] = 0;
				m_pc[i] = 0;
				m_user[i] = 0;
			}
		}
	} while (bulls != kolvo);
	printf("Congratulations! You won!");					//pobeda!
	return 0;
}



