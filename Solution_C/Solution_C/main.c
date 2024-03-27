#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Athlete {
    char fullName[100];
    char gender[10];
    char birthdate[10];
    char nationality[100];
    char origin[100];
    char sport[100];
    char club[100];
    float personalRecord;
};

int readAthletesFromFile(struct Athlete** athletes, int* numAthletes, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file: %s\n", filename);
        return 0;
    }

    int maxAthletes = 10;
    *athletes = (struct Athlete*)malloc(maxAthletes * sizeof(struct Athlete));
    *numAthletes = 0;

    char line[200];
    while (fgets(line, sizeof(line), file)) {
        if (*numAthletes >= maxAthletes) {
            maxAthletes *= 2;
            *athletes = (struct Athlete*)realloc(*athletes, maxAthletes * sizeof(struct Athlete));
        }

        sscanf(line, "%s %s %s %s %s %s %s %f", (*athletes)[*numAthletes].fullName,
            (*athletes)[*numAthletes].gender, (*athletes)[*numAthletes].birthdate,
            (*athletes)[*numAthletes].nationality, (*athletes)[*numAthletes].origin,
            (*athletes)[*numAthletes].sport, (*athletes)[*numAthletes].club,
            &(*athletes)[*numAthletes].personalRecord);

        (*numAthletes)++;
    }

    fclose(file);
    return 1;
}

void printAthlete(const struct Athlete* athlete) {
    printf("Full Name: %s\n", athlete->fullName);
    printf("Gender: %s\n", athlete->gender);
    printf("Birthdate: %s\n", athlete->birthdate);
    printf("Nationality: %s\n", athlete->nationality);
    printf("Origin: %s\n", athlete->origin);
    printf("Sport: %s\n", athlete->sport);
    printf("Club: %s\n", athlete->club);
    printf("Personal Record: %.2f\n", athlete->personalRecord);
    printf("--------------------------\n");
}

void searchAthletesBySport(const struct Athlete* athletes, int numAthletes, const char* sport) {
    printf("Athletes in %s:\n", sport);
    for (int i = 0; i < numAthletes; i++) {
        if (strcmp(athletes[i].sport, sport) == 0) {
            printAthlete(&athletes[i]);
        }
    }
}

void searchAthletesForEachSport(const struct Athlete* athletes, int numAthletes) {
    printf("Athletes in each sport:\n");
    char sports[100][100];
    int numSports = 0;


    for (int i = 0; i < numAthletes; i++) {
        int found = 0;
        for (int j = 0; j < numSports; j++) {
            if (strcmp(sports[j], athletes[i].sport) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(sports[numSports], athletes[i].sport);
            numSports++;
        }
    }


    for (int i = 0; i < numSports; i++) {
        printf("Sport: %s\n", sports[i]);
        for (int j = 0; j < numAthletes; j++) {
            if (strcmp(sports[i], athletes[j].sport) == 0) {
                printAthlete(&athletes[j]);
            }
        }
        printf("==========================\n");
    }
}

int main() {
    struct Athlete* athletes;
    int numAthletes;

    if (readAthletesFromFile(&athletes, &numAthletes, "sportIN.txt")) {
        int choice;
        do {
            printf("Menu:\n");
            printf("1. Print all athletes\n");
            printf("2. Search athletes by sport\n");
            printf("3. Search athletes for each sport\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
            case 1:
                printf("\nAll athletes:\n");
                for (int i = 0; i < numAthletes; i++) {
                    printAthlete(&athletes[i]);
                }
                break;
            case 2:
                char sport[100];
                printf("Enter the sport: ");
                scanf("%s", sport);
                searchAthletesBySport(athletes, numAthletes, sport);
                break;
            case 3:
                searchAthletesForEachSport(athletes, numAthletes);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
            }
        } while (choice != 4);
    }

    free(athletes);
    return 0;
}