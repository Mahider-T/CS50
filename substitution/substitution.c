#include <cs50.h>
#include <stdio.h>
#include <string.h>
void transformer(char arrayNormal[],char arrayKey[], string plainText);
int positionOfCharacter(char array[], char targetCharacter);


int main(int argc, string argv[])
{
    char alphabetArray[] = {'A', 'B', 'C','D', 'E', 'F','G', 'H', 'I','J', 'K', 'L', 'M', 'N', 'O','P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char keyArray[26];
    string key = argv[1];
    for(int i = 0; i < 26; i++){
        keyArray[i] = key[i];
    }
    string plainText = get_string("Plain text:");
    transformer(alphabetArray, keyArray, plainText);

}

//Enter the key
//Normal array of alphabet A = 1 and Z = 26
//When the key is entered, put each character into a new array
void transformer(char arrayNormal[],char arrayKey[], string plainText){
    int lengthOfString = strlen(plainText);
    int positionOfChar;
    for(int i = 0; i < lengthOfString; i++){
        positionOfChar = positionOfCharacter(arrayNormal, plainText[i]);
        printf("%c",arrayKey[positionOfChar]);
    }
}

int positionOfCharacter(char array[], char targetCharacter){
    for(int i = 0; i < 26; i++){
        if(array[i] == targetCharacter){
            return i-1;
        }
    }
    return 1;
}