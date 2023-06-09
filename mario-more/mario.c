#include <stdio.h>

void pyramid(int height);

int main() {
    int number;

    while (1) {
        printf("Enter the length of the base of the pyramid: ");
        if (scanf("%d", &number) != 1 || number < 1 || number >= 9) {
            printf("Please input a positive numeric value between 1 and 8.\n");
            while (getchar() != '\n') {}  // Clear input buffer
        }
        else {
            break;
        }
    }

    pyramid(number);

    return 0;
}

void pyramid(int height) {
    for (int i = 1; i <= height; i++) {
        for (int j = height; j > i; j--) {
            printf(" ");
        }
        for (int k = 1; k <= i; k++) {
            printf("#");
        }
        printf("  ");
        for (int k = 1; k <= i; k++) {
            printf("#");
        }
        printf("\n");
    }
}