#include <cs50.h>
#include <stdio.h>
#include <string.h>
void transformer(char arrayNormal[],char arrayKey[], string plainText);
int positionOfCharacter(char array[], char targetCharacter);


int main(int argc, string argv[])
{
    const char alphabetArray[] = {'A', 'B', 'C','D', 'E', 'F','G', 'H', 'I','J', 'K', 'L', 'M', 'N', 'O','P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y/', 'Z'};
    const string key = argv[1];
    for(i)
    transformer(alphabetArray, key, plainText);

}

//Enter the key
//Normal array of alphabet A = 1 and Z = 26
//When the key is entered, put each character into a new array
void transformer(char arrayNormal[],char arrayKey[], string plainText){
    int lengthOfString = strlen(plainText);
    int positionOfChar;
    for(int i = 0; i < lengthOfString; i++){
        positionOfChar = positionOfCharacter(plainText[i]);
        printf(arraykey[positionofChar]);
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