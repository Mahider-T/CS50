#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");
    printf("%s\n", text);
}

int count_letters(string text){
    int lengthOfString = strlen(text);
    int count = 0;
    
    for( int i= 0; i < lengthOfString; i++){
        if(strcmp(text[i], " ")){
            continue;
        }
        else{
            count++;
        }
    }
    return count;
}