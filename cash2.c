#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXBUFFERSIZE       80

int greedy(int n);
void getAnInput(void) ;

int greedy(int n) {
    int v[4] = {25, 10, 5, 1};
    int coins = 0;
    for (int i = 0; i < 4; i++)  {
        coins += n / v[i];
        n %= v[i];
    }
    return coins; 
}

void getAnInput(void) {
    char c;
    char buffer[MAXBUFFERSIZE];
    int valid_choice = 0;
    int char_count = 0;
    int i_number;
    float f_number;
    
    do {
        printf("Change owed:  ");
        c = getchar();
        char_count = 0;
        while ((c != '\n') && (char_count < MAXBUFFERSIZE ) ) {
            buffer[char_count++] = c;
            c = getchar();
        }
        buffer[char_count] = 0x00;

        i_number = atoi(buffer);
        f_number = atof(buffer);
        if (i_number ) {
            valid_choice = 1;
            printf("%i\n", greedy(round(i_number * 100)));
        } else if (f_number) {
            valid_choice = 1;
            printf("%i\n", greedy((int)round(f_number * 100)));
        }
    } while(valid_choice == 0);
}

int main(void) {
    getAnInput();
    return 0;
}