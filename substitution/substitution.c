#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void transformer(char arrayNormal[],char arrayKey[], string plainText);
int positionOfCharacter(char array[], char targetCharacter);
bool has_duplicate(char characters[]);


int main(int argc, string argv[])
{
    if(argc != 2){
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if(strlen(argv[1]) != 26){
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    if(has_duplicate(argv[1])){
        
    }


    char alphabetArray[] = {'A', 'B', 'C','D', 'E', 'F','G', 'H', 'I','J', 'K', 'L', 'M', 'N', 'O','P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char keyArray[26];
    string key = argv[1];
    for(int i = 0; i < 26; i++){
        if(!isalpha(key[i]){

        }
        keyArray[i] = toupper(key[i]);
    }
    string plainText = get_string("Plain text:");
    char initialText[strlen(plainText)];
    for(int i = 0; i < strlen(plainText); i++){
        initialText[i] = toupper(plainText[i]);
    }
    // for(int i = 0; i < strlen(plainText); i++){
    //     printf("%c", initialText[i]);
    // }


    transformer(alphabetArray, keyArray, initialText);

}

//Enter the key
//Normal array of alphabet A = 1 and Z = 26
//When the key is entered, put each character into a new array
void transformer(char arrayNormal[],char arrayKey[], string plainText){
    // printf("%s\n", plainText);
    // printf("%c",plainText[0]);
    int lengthOfString = strlen(plainText);
    // printf("%i\n",lengthOfString);
    int positionOfChar;
    for(int i = 0; i < lengthOfString; i++){
        positionOfChar = positionOfCharacter(arrayNormal, plainText[i]);
        printf("%c",arrayKey[positionOfChar]);
    }
    printf("\n");
}

int positionOfCharacter(char array[], char targetCharacter){
    for(int i = 0; i < 26; i++){
        if(array[i] == targetCharacter){
            return i;
        }
    }
    return 1;
}

bool has_duplicate(char characters[]){
    for(int i = 0; i < strlen(characters); i++){
        for(int j = 0; j < strlen(characters); j++){
            if(characters[i] = characters[j]){
                return 1;
            }
            return 0;
        }
    }
}