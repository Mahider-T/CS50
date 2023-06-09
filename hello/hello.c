#include <stdio.h>
#include <stdlib.h>

conts NAME_LENGTH 100;

int main()
{
    char name[NAME_LENGTH];

    printf("What is your name : ");
    scanf("%99s", name);  
    printf("Hello, %s!\n", name);

    getchar();
    return 0;
}