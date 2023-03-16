#ifndef _USERSIDE_H
#define _USERSIDE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileProcessing.h"
#define MAX_LEN_ANSWER 100

// Два раза использовался switch -- вынес в функцию из-за его объемности!
// Переводит название формы обучения из константы в слово)
char* switch_form(EducationalForm form);

//Для ВУЗов
// Берет от пользователя название ВУЗа, работает пока не будет введет существующий вуз
int getting_univ(University_t* uns, int c, char in[]);

// Проверка, что введены 1 или 2 для вызова мода
void entering_mode(char in[]);

// Поиск минимального конкурса по специальностям каждого конкретного вуза
void print_minimal_spec(University_t* uns, int c, char name_univ[MAX_LEN_ANSWER], int ind);

// Всё о данном ВУЗе
void print_all_about_univ(University_t* uns, int c, char name_univ[MAX_LEN_ANSWER], int ind);

// возвращает индекс вуза в массиве структур вузов, или -1, если не нашёл
int check_index_univ(University_t* uns, int c, char name_univ[MAX_LEN_ANSWER]);

// функция запускает работу с университетами
void about_univercity(University_t* uns, int c);

// Для специальностей
// функция запускает работу с специальностями
void about_spec(University_t* uns, int c);

// Проверяет существование специальности
int check_existing_spec(University_t* uns, int c, char name_spec[MAX_LEN_ANSWER]);

// Всё о данной специальности
void print_all_about_spec(University_t* uns, int c, char name_spec[MAX_LEN_ANSWER]);

// берет от пользователя название специальности, работает пока не будет введет существующая специальность
void getting_spec(University_t* uns, int c, char name_spec[MAX_LEN_ANSWER]);

// Поиск минимального конкурса по специальности
void print_min_score_for_spec(University_t* uns, int c, char name_spec[MAX_LEN_ANSWER]);

// Проверка, что введены 1 или 2 или 0 для вызова мода
void main_entering_mode(char in[]);

// основаная функция работы с пользователем
void working_with_user(University_t* uns, int c);

#endif