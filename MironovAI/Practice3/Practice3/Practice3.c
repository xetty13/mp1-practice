#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max_length 5

int check_input_data(int num, int n) {
    int c = 0, f = 0;
    int a[max_length];

    while (num > 0) {
        a[n - c - 1] = num % 10;
        c++;
        num = num / 10;
    }

    //Checking length
    if (c != n) return 1;

    //checking unique digits
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                f++;
                return 1;
            }
        }
    }
    return 0;

}
int random_digits() {
    int n;

    srand((unsigned int)time(NULL));
    n = rand() % (10);

    return n;
}


int number_generator(int length) {


    int a[max_length] = { -1,-1,-1,-1,-1 };
    for (int i = 0; i < length; i++) {
        int num = random_digits();

        if (i == 0) {
            while (num == 0) {
                num = random_digits();
            }
            a[i] = num;
            continue;
        }


        int f = 0;
        for (int j=0; j < i; j++) {
            if (a[j] == num){
                f++;
            }
            
        }


        while (f != 0) {
            num = random_digits();
            f = 0;
            for (int q=0; q < i+1; q++) {
                if (a[q] == num) f++;
            }
        }
        a[i] = num;
    }

    int s=0, k = length-1;
    for (int i = 0; i < length; i++) {

        
        int s1 = 1;
        for (int j = 0; j < k; j++) {
           s1 *= 10;
        }
        s += a[i] * s1;
        k--;
    }
    return s;
}

int main() {
    int n, mac_num, number, mac[max_length], user[max_length], count = 0;
   


    //Input data
    printf("Input a length  ");
    scanf("%d", &n);

    while (n < 2 || n > 5) {
        printf("For this game u must to input a length from 2 to 5 \n ");
        printf("Input a length  ");
        scanf("%d", &n);
    }


    //Random number with unique digits length (n)
    printf("A machine mades the number, wait a sec it. \n");
    mac_num = number_generator(n);
    printf("%d \n", mac_num);
    printf("Done! we can start!  \n");

    
    while (count != 100) {
        //Counter attempts
        count++;
        int mac_num1 = mac_num;
        printf("Input a number with unique digits length %d: ", n);
        scanf("%d", &number);

        if (check_input_data(number, n) == 1) {
            while (check_input_data(number, n) == 1) {
                printf("Pls be sure that u writed a right number. \n The number must have %d unique digits. Pls try to guess again:  ", n);
                scanf("%d", &number);
            }
        }

        //Win
        if (mac_num == number) {
            printf("Congretulations! You win for the %d attempts. Let`s play again! ", count);
            return 0;
        }

        //fill 2 arrays for counting cows and bulls
        for (int i = 0; i < n; i++) {
            mac[n - i - 1] = mac_num1 % 10;
            user[n - i - 1] = number % 10;
            mac_num1 = mac_num1 / 10;
            number = number / 10;

        }

        //Cows and bulls counter
        int cows = 0, bulls = 0;
        for (int i = 0; i < n; i++) {
            if (mac[i] == user[i]) bulls++;
            for (int j = 0; j < n; j++) {
                if (mac[i] == user[j] && i != j) cows++;
            }
        }

        if (cows == 0 && bulls == 0) printf("xd you dont have any cows and bulls lol, try again ");
        else printf("You didn`t guess, but u have %d cows and %d bulls ", cows, bulls);

        if (count % 10 == 0) printf("You have %d attempts ", count);
    }
     


     
    printf("You have 100 attempts.It is sad, however you`ve lost");
    return 1;
}