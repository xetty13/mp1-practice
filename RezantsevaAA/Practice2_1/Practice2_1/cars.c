#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "cars.h"
#include <stdlib.h>

// dynamic reading for str
char* read_string(FILE* stream)
{
    int buffer_size = 16;
    int buffer_size_divizer = 1;
    int offset = 0;
    int additional_length;

    char* buffer = (char*)malloc(buffer_size);
    if (buffer == NULL) {
        return NULL;
    }
    buffer[0] = '\0';

    // read string while not face with '\n'
    while (1) {
        // read string to buffer with current offset
        if (fgets(buffer + offset, buffer_size / buffer_size_divizer, stream) == NULL) {
            free(buffer); // free allocated memory
            return NULL;
        }
        else {
            additional_length = strlen(buffer + offset);
            if (buffer[offset + additional_length - 1] != '\n') {
                // increase buffer_size by 2 times
                buffer_size *= 2;
                // realloc new memory
                buffer = (char*)realloc(buffer, buffer_size);
                // update offset to number of read elements
                offset += additional_length;
                buffer_size_divizer = 2;
            }
            else {
                buffer[offset + additional_length - 1] = '\0';
                break;
            }
        }
    }
    return buffer;
}

char* getPath()
{
    char* file_path;
    while (1) {
        printf("Enter the path to file : ");
        file_path = read_string(stdin);
        if (file_path != NULL)
            break;
    }
    return file_path;
}

Car ReadCarEntity(FILE* file)
{
    char* car_brand = read_string(file);
    char* car_color = read_string(file);
    char* car_serial_number = (read_string(file));
    char* car_registration_number = (read_string(file));
    int car_count_door = atoi(read_string(file));
    int car_year = atoi(read_string(file));
    int car_price = atoi(read_string(file));

    Car new_car = { car_brand, car_color, car_serial_number, car_registration_number, car_count_door, car_year, car_price };
    return new_car;
}

Car* ReadCarFile(char* file_path, int* number_of_cars)
{
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("\nRead file error.\n");
    }
    Car* cars = (Car*)malloc(sizeof(Car));
    *number_of_cars = 1;

    // we assume that the file contains information about at least one car
    while (1) {
        Car current_car = ReadCarEntity(file);
        cars[*number_of_cars - 1] = current_car;
        if (read_string(file) == NULL) {
            break;
        }
        else {
            cars = (Car*)realloc(cars, (*number_of_cars + 1) * sizeof(Car));
            *number_of_cars += 1;
        }
    }
    fclose(file);
    return cars;
}

Car FindOldestCar(Car* cars, int count_of_cars)
{
    Car oldest_car = cars[0];
    for (int i = 1; i < count_of_cars; ++i) {
        if (cars[i].year < oldest_car.year) {
            oldest_car = cars[i];
        }
    }
    return oldest_car;
}

void PrintCar(Car car)
{
    printf("Brand: %s\n", car.brand);
    printf("Color: %s\n", car.color);
    printf("Serial number: %s\n", car.serial_number);
    printf("Registration number: %s\n", car.registration_number);
    printf("Numbers of doors: %d\n", car.count_door);
    printf("Year of car manufacture: %d\n", car.year);
    printf("Price: %d\n\n", car.price);
}