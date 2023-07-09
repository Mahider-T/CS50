# TODO
from cs50 import get_string

def count_sentences(text):
    count = 0
    for i in text:
        if i == '.' or i == '?' or i == '!':
            count += 1
    return count

def count_words(text):
    count = 1
    for i in text:
        if i == ' ':
            count += 1
    return count

def count_letters(text):
    count = 0
    for i in text:
        if i.isalpha() == True:
            count += 1
    return count




def level(text):
    numberOfLetters = count_letters(text)
    numberOfWords = count_words(text)
    numberOfSentences = count_sentences(text)

    l = float(numberOfLetters)/float(numberOfWords)*float(100)
    s = float(numberOfSentences)/float(numberOfWords)*float(100)
    index = (0.0588 * l) - (0.296 * s) - 15.8
    finalIndex = round(index)

    if index >= 16:
        return "Grade 16+"
    elif index < 1:
        return "Before Grade 1"
    else:
        return "Grade " + str(finalIndex)


def main():
    string = get_string("Text: ")
    print(level(string))

if __name__ == "__main__":
    main()