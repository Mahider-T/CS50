#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 100

int main()
{
    char name[MAX_NAME_LENGTH];

    printf("Enter your name: ");
    scanf("%99s", name);  // Use %99s to prevent buffer overflow (leaving space for null terminator)

    printf("Hello, %s!\n", name);

    getchar();
    return 0;
}