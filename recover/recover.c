#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if( argc != 2){
        printf("usage ./recover image\n");
        return 1;
    }

    char *photo = argv[1];
    FILE *file = fopen(photo, "r");

    if (file == NULL)
    {
        printf("Could not open %s.\n", photo);
        return 1;
    }

}