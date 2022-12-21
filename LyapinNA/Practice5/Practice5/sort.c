#include <stdio.h>
#include "SORT.h"





//Простая сортировка
void sorto(unsigned long long int* a, int maxel) {
	unsigned long long int slide;
	for (int i = 0; i < maxel - 1; i++) {
		for (int j = i + 1; j < maxel; j++) {
			if (a[i] > a[j]) {
				slide = a[i];
				a[i] = a[j];
				a[j] = slide;
			}
		}
	}
}

//Пузырьком
void sortb(int* m, int n) {
	int slide, k;
	while (n > 1) {
		k = 0;
		for (int i = 1; i < n; ++i) {
			if (m[i] > m[i - 1]) {
				slide = m[i];
				m[i] = m[i - 1];
				m[i - 1] = slide;
				k = i;
			}
		}
		n = k;
	}

}

//Быстрая сортировка
void fastsort(long long int* array, int first, int last) {
	if (first < last) {
		long long int tmp;
		int left = first; //0
		int right = last; //N
		long long int middle = array[(left + right) / 2];
		do {
			while (array[left] < middle)
				left++;
			while (array[right] > middle)
				right--;
			if (left <= right) {
				tmp = array[left];
				array[left] = array[right];
				array[right] = tmp;
				left++;
				right--;
			}
		} while (left < right);
		fastsort(array, first, right);
		fastsort(array, left, last);
	}
	return;
}

//Сортировка вставками
void insert_sort(unsigned long long  int* mas, int LIMIT) {
	for (int i = 1; i < LIMIT; i++) {
		int location = i, tmp;
		while ((mas[location] < mas[location - 1]) && (location > 0)) {
			tmp = mas[location];
			mas[location] = mas[location - 1];
			mas[location - 1] = tmp;
			location--;
		}
	}

}