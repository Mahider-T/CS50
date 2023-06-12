#include <cs50.h>
#include <stdio.h>
#include <string.h>
int count_letters(string text);

int main(void)
{
    string text = get_string("Text: ");
    int numberOfLetters = count_letters(text);

    printf("%i\n", numberOfLetters);
}

int count_letters(string text){
    int lengthOfString = strlen(text);
    int count = 0;
    char character;

    for( int i= 0; i < lengthOfString; i++){
        character = text[i];
        if(character  ){
            continue;
        }
        else{
            count++;
        }
    }
    return count;
}