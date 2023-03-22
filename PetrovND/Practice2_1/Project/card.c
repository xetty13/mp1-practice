#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "card.h"
#define LENGTH 512

cardIndex* alloc(int stringCount, int authorsCount) {
    int i, g;
    cardIndex* cards = (cardIndex*)malloc(stringCount * sizeof(cardIndex));
    for (i = 0; i < stringCount; i++) {
        cards[i].authors = (char**)malloc(authorsCount * sizeof(char*));
        for (g = 0; g < authorsCount; g++) {
            cards[i].authors[g] = (char*)malloc(128 * sizeof(char));
        }
    }
    return cards;
}

void memoryFree(cardIndex* cards, int stringCount, char** section, int authorsCount) {
    int i,g;
    for (i = 0; i < stringCount; i++) {
        for (g = 0; g < authorsCount; g++) {
            free(cards[i].authors[g]);
        }
        free(cards[i].authors);
    }
    free(cards);
    for (i = 0; i < stringCount; i++) {
        free(section[i]);
    }
    free(section);
}

int strCount(char* path) {
    int count = 0;
    char* s = (char*)malloc(1000 * sizeof(char));
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        printf("ERROR: Could not open file!\n");
        return 1;
    }
    while (1) {
        if (fgets(s, 1000, file) != NULL) {
            if (strcmp(s, "\n") != 0) {
                count++;
            }
        }
        else {
            break;
        }
    }
    fclose(file);
    free(s);
    return count;
}

void readFile(cardIndex* cards, char* path, int stringCount, int authorsCount) {
    char* token;
    char delim[] = ";\n";
    int i = 0;
    int j = 0;
    int g;
    char** b = (char**)malloc(stringCount * sizeof(char*));
    for (g = 0; g < stringCount; g++) {
        b[g] = (char*)malloc(128 * sizeof(char));
    }
    FILE* file = fopen(path, "r");
    char str [LENGTH];
    if (file == NULL) {
        printf("ERROR: Could not open file!\n");
        return 1;
    }
    while (1) {
        if (fgets(str, 512, file) != NULL) {
            for (token = strtok(str, delim); token; token = strtok(NULL, delim)) {
                switch (i) {
                case 0:
                    strcpy(b[j], token);
                    break;
                case 1:
                    strcpy(cards[j].title, token);
                    break;
                case 2:
                    strcpy(cards[j].publisher, token);
                    break;
                case 3:
                    strcpy(cards[j].section, token);
                    break;
                case 4:
                    if (strcmp(token, "Available") == 0) {
                        cards[j].avb = AVAILABLE;
                    }
                    else {
                        cards[j].avb = UNAVAILABLE;
                    }
                    break;
                case 5:
                    cards[j].evaluation = strtof(token, NULL);
                    i = -1;
                    j++;
                    break;
                }
                i++;
            }
        }
        else {
            break;
        }
    }
    for (i = 0; i < stringCount; i++) {
        g = 0;
        for (token = strtok(b[i], ","); token; token = strtok(NULL, ",")) {
            strcpy(cards[i].authors[g], token);
            g++;
        }
        for (; g < authorsCount; g++) {
            strcpy(cards[i].authors[g], "NULL");
        }
    }
    for (g = 0; g < stringCount; g++) {
        free(b[g]);
    }
    free(b);
    fclose(file);
}

int isEqual(char** mass, char* word, int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(mass[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

int countSubs(char* string, char* sub) {
    int l = strlen(sub);
    int n = 0;
    while ((string = strstr(string, sub)) != NULL) {
        ++n;
        string += l;
    }
    return n;
}

int authorsCount(char* path, int stringCount) {
    char* token;
    char delim[] = ";\n";
    int i = 0;
    int j = 0;
    int count = 0;
    int g;
    FILE* file = fopen(path, "r");
    char str[LENGTH];
    if (file == NULL) {
        printf("ERROR: Could not open file!\n");
        return 1;
    }
    while (1) {
        if (fgets(str, 512, file) != NULL) {
            for (token = strtok(str, delim); token; token = strtok(NULL, delim)) {
                switch (i) {
                case 0:
                    if (count > countSubs(token, ",")) {
                        break;
                    }
                    count = countSubs(token, ",");
                    break;
                case 5:
                    i = -1;
                    j++;
                    break;
                }
                i++;
            }
        }
        else {
            break;
        }
    }
    fclose(file);
    return count+1;
}

void bookPrint(cardIndex* cards, int authorsCount, int g) {
    int j;
    printf("--------------|--------------\n");
    printf("%s\n", cards[g].title);
    printf("Authors: ");
    for (j = 0; j < authorsCount; j++) {
        if (strcmp(cards[g].authors[j], "NULL") == 0)
            continue;
        printf("%s", cards[g].authors[j]);
    }
    printf("\n");
    printf("Publisher: %s\n", cards[g].publisher);
    printf("Availability: ");
    if (cards[g].avb == 0) {
        printf("available\n");
    }
    else {
        printf("unavailable\n");
    }
    printf("Evaluation: %.1f\n", cards[g].evaluation);
}

char** booksBySection(cardIndex* cards, int stringCount, int authorsCount) {
    int ind = 0;
    int i;
    char** section = (char**)malloc(stringCount * sizeof(char*));
    for (i = 0; i < stringCount; i++) {
        section[i] = (char*)malloc(100 * sizeof(char));
    }
    for (i = 0; i < stringCount; i++) {
        if (isEqual(section, cards[i].section, stringCount) == 0) {
            strcpy(section[ind], cards[i].section);
            ind++;
        }
    }
    int tmp = ind;
    for (; tmp < stringCount; tmp++) {
        section[tmp] = NULL;
    }
    for (i = 0; i < stringCount; i++) {
        if (section[i] == NULL)
            continue;
        printf("\nBooks from %s:\n", section[i]);
        for (int g = 0; g < stringCount; g++) {
            if (strcmp(cards[g].section, section[i]) == 0) {
                bookPrint(cards, authorsCount, g);
            }
        }
    }
    return section;
}

void selectBook(cardIndex* cards, char** section, int stringCount, int authorsCount) {
    int sectionCount = 0;
    int i;
    int j = 0;
    int userInput;
    int* indexes = (int*)malloc((stringCount+1) * sizeof(int));
    for (i = 0; i < stringCount; i++) {
        if (section[i] != NULL) {
            sectionCount++;
        }
    }
    do{
        printf("\nSelect the library section you are interested in:\n");
        for (i = 0; i < sectionCount; i++) {
            printf("%d) %s\n", i, section[i]);
        }
        if (scanf("%d", &userInput) != 1) {
            printf("Scanf error!");
            return 1;
        }
    } while (userInput > i-1 || userInput < 0);

    for (i = 0; i < stringCount; i++) {
        if (strcmp(cards[i].section, section[userInput]) == 0) {
            printf("%d) %s\n", j, cards[i].title);
            indexes[j] = i;
            j++;
        }
    }
    do {
        printf("\nChoose the book you are interested in:\n");
        if (scanf("%d", &userInput) != 1) {
            printf("Scanf error!");
            return 1;
        }
    } while (j-1 < userInput || userInput < 0);
    for (i = 0; i < stringCount; i++) {
        if (strcmp(cards[i].title, cards[indexes[userInput]].title) == 0) {
            bookPrint(cards, authorsCount, i);
            break;
        }
    }
    free(indexes);
}