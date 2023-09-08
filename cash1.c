 #include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXBUFFERSIZE    80

int greedy(int n);

int greedy(int n) {
    int v[4] = {25, 10, 5, 1};
    int coins = 0;
    for (int i = 0; i < 4; i++) {
       coins += n / v[i];
       n %= v[i];
    }
  return coins;  
}

int main(void) {
    char c;
    char buffer[MAXBUFFERSIZE];
    int char_count = 0;
    int i_number, valid_choice;
    float f_number;

    valid_choice = 0;
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
    
    return 0;
}
    
    // read a char from key board
    // convert char  in int
    //convert char in float
    // if return is 1 do greedy() -> out of the loop
    //... else repeat until input is an integer or a float

   




