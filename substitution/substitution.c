#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{

}

//Enter the key
//Normal array of alphabet A = 1 and Z = 26
//When the key is entered, put each character into a new array
char transformer(char arrayNormal[],char arrayKey[], string plainText){
    int lengthOfString = strlen(plainText);
    int positionOfChar;
    for(int i = 0; i < lengthOfString; i++){
        positionOfChar = positionOfCharacter()
    }
}

int positionOfCharacter(char array[], char targetCharacter){
    for(int i = 0; i < 26; i++){
        if(array[i] == targetCharacter){
            return i;
        }
    }
    return 1;
}