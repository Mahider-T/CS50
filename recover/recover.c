#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;
    char block[512];


    if( argc != 2){
        printf("usage ./recover image\n");
        return 1;
    }

    // char *photo = argv[1];
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    while (fread(&block, 512, 1, file) == 512)
    {
        if(block[1] == 0xff )

    }


}