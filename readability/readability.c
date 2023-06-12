#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int count_letters(string text);
int count_words(string text);

int main(void)
{
    string text = get_string("Text: ");
    int numberOfLetters = count_letters(text);

    printf("%i words\n", numberOfLetters);
}

int count_letters(string text){
    int lengthOfString = strlen(text);
    int count = 0;
    char character;

    for( int i= 0; i < lengthOfString; i++){
        character = toupper(text[i]);
        if(character < 65 || character > 90){
            continue;
        }
        else{
            count++;
        }
    }
    return count;
}

int count_words(string text){
    int count;
    char spaceCheck;
    for( int i = 0; i < strlen(text); i++){
        spaceCheck = text[i];
        if(spaceCheck == ' '){
            count++;
        }
    }
    return count;
}