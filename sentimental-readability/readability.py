# TODO
def count_sentences(text):
    count = 1
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

def main():
    print(count_letters("What is"))

if __name__ == "__main__":
    main()