#include "outlet.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
	char* path = start();
	int outletCount = count(path); // функция считает количество торговых точек
	outlet* retail_outlets = allocateMemory(outletCount, path);//выделение памяти
	readDataFromFile(retail_outlets, path, outletCount);//считывает данные из файла и записывает в элементы массива retail_outlets
	all_time(retail_outlets, outletCount);//выводит круглосуточные магазины
	memoryFree(retail_outlets, outletCount);//освобождение памяти
	return 0;
}