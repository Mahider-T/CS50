# TODO
def numberOfSentences(text):
    count = 1
    for i in text:
        if i == '.' or i == '?' or i == '!':
            count += 1
    return count
def main():
    print(numberOfSentences("What is your name? My nane is Mahider, How about you? bro!"))

if __name__ == "main":
    main()