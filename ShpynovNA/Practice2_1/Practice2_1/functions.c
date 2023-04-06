#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <memory.h>
#include <string.h>

void scanstring(char** tmpstr,FILE* file)
{
	fgets(*tmpstr, 350, file);
}

void set_data(char** data, const char* value)
{
	*data = (char*)malloc(strlen(value) + 1);
	strcpy(*data, value);
}

void struct_free(struct EmployeesInfo_t* g_empls, struct Pasports_t* g_pspts)
{
	free(g_empls->name);
	free(g_empls->appnt);
	free(g_empls->edu);
	free(g_empls->spec);
	free(g_empls->unit);
	free(g_pspts->auth);
	free(g_pspts->issue);
	free(g_pspts);
	free(g_empls);

}

void* get_target(void* base, int size, int index)
{
	return (void*)((char*)base + (size * index));
}

void set_data_char(void* base, int size, int index, char* value)
{
	char** target = (char**)get_target(base, size, index);

	*target = (char*)malloc(strlen(value)+1);
	strcpy(*target, value);
}

void set_data_int(void* base, int size, int index, int value)
{
	int* target = (int*)get_target(base, size, index);
	*target = value;
}

void read_str(FILE* file, int n, void* target, size_t struct_size)
{
	char str[350];
	fgets(str, 350, file);
	char tmp[30];
	for (int i = 0, g = 0; i < n; i++)
	{

		for (int j = g; j < g + 30; j++) {
			if (str[j] == ';') {
				tmp[j - g] = '\0';
				g = j + 1;
				break;
			}
			tmp[j - g] = str[j];
		}

		set_data_char(target, struct_size, i, tmp);
	}
}

void read_int(FILE* file, int n, void* target, size_t struct_size)
{
	char str[350];
	fgets(str, 350, file);
	for (int i = 0, g = 0; i < n; i++)
	{
		int tmp = 0;
		for (int j = g; j < g + 30; j++) {
			if (str[j] == ';') {
				g = j + 1;
				break;
			}
			tmp = tmp * 10 + (int)str[j] - 48;
		}
		set_data_int(target, struct_size, i, tmp);
	}
}
void allocstructmem(int n, char* filename, struct EmployeesInfo_t** g_empls, struct Pasports_t** g_pspts)
{
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("error");
		exit(ENFILE);
	}
	const size_t empl_size = sizeof(struct EmployeesInfo_t);
	const size_t pspts_size = sizeof(struct Pasports_t);
	*g_empls = malloc(empl_size * n);
	*g_pspts = malloc(pspts_size * n);

	char str[350];
	int tmp[3];

	struct EmployeesInfo_t* empls = *g_empls;
	struct Pasports_t* pspts = *g_pspts;

	read_str(file, n, &(empls->name), empl_size);
	read_int(file, n, &(pspts->series), pspts_size);
	read_int(file, n, &(pspts->number), pspts_size);
	read_str(file, n, &(pspts->auth), pspts_size);
	read_str(file, n, &(pspts->issue), pspts_size);
	fgets(str, 350, file);
	for (int i = 0, g = 0; i < n; i++) {
		(*g_pspts)[i].birth.day = ((int)str[g] - 48) * 10 + (int)str[g + 1] - 48;
		(*g_pspts)[i].birth.month = ((int)str[g + 3] - 48) * 10 + (int)str[g + 4] - 48;
		(*g_pspts)[i].birth.year = ((int)str[g + 8] - 48) * 10 + (int)str[g + 9] - 48;
		g += 11;
	}
	fgets(str, 350, file);
	for (int i = 0, g = 0; i < n; i++) {
		(*g_pspts)[i].reg.day = ((int)str[g] - 48) * 10 + (int)str[g + 1] - 48;
		(*g_pspts)[i].reg.month = ((int)str[g + 3] - 48) * 10 + (int)str[g + 4] - 48;
		(*g_pspts)[i].reg.year = ((int)str[g + 8] - 48) * 10 + (int)str[g + 9] - 48;
		g += 11;
	}
	read_str(file, n, &(empls->edu), empl_size);
	read_str(file, n, &(empls->spec), empl_size);
	read_str(file, n, &(empls->unit), empl_size);
	read_str(file, n, &(empls->appnt), empl_size);
	fgets(str, 350, file);
	for (int i = 0, g = 0; i < n; i++) {
		(*g_empls)[i].dateofappnt.day = ((int)str[g] - 48) * 10 + (int)str[g + 1] - 48;
		(*g_empls)[i].dateofappnt.month = ((int)str[g + 3] - 48) * 10 + (int)str[g + 4] - 48;
		(*g_empls)[i].dateofappnt.year = ((int)str[g + 8] - 48) * 10 + (int)str[g + 9] - 48;
		g += 11;
	}
	fgets(str, 350, file);
	for (int i = 0, g = 0; i < n; i++) {
		(*g_empls)[i].lastdate.day = ((int)str[g] - 48) * 10 + (int)str[g + 1] - 48;
		(*g_empls)[i].lastdate.month = ((int)str[g + 3] - 48) * 10 + (int)str[g + 4] - 48;
		(*g_empls)[i].lastdate.year = ((int)str[g + 8] - 48) * 10 + (int)str[g + 9] - 48;
		g += 11;
	}
	fclose(file);
}

void age_scan(int n, struct EmployeesInfo_t* g_empls, struct Pasports_t* g_pspts) {
	for (int i = 0; i < n; i++) {
		if ((g_pspts[i].birth.year<58) || ((g_pspts[i].birth.year == 58) && ((g_pspts[i].birth.month < 4) || ((g_pspts[i].birth.month == 4) && (g_pspts[i].birth.day <= 6)))))
			if (g_pspts[i].birth.day < 10) {
				printf("%s - 0%d.", g_empls[i].name, g_pspts[i].birth.day);
				if (g_pspts[i].birth.month < 10)
					printf("0%d.19%d\n", g_pspts[i].birth.month, g_pspts[i].birth.year);
			} else if (g_pspts[i].birth.month < 10)
				printf("%s - %d.0%d.19%d\n", g_empls[i].name, g_pspts[i].birth.day, g_pspts[i].birth.month, g_pspts[i].birth.year);
			else 
				printf("%s - %d.%d.19%d\n", g_empls[i].name, g_pspts[i].birth.day, g_pspts[i].birth.month, g_pspts[i].birth.year);
	}
}
