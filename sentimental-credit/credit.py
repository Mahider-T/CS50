# TODO
from cs50 import get_int, get_string
def getDigitSum(number):
    sum = 0
    while(number > 0):
        sum += number % 10
        number /= 10
    return sum
def isValidCreditCard(number):
    empty = []
    string = str(number)
    for numbers in string:
        empty.append(int(numbers))
    
    # print(empty)

# def getCardType():

def main():
    card = get_string("Enter the credit card number: ")
    isValidCreditCard(card)




if __name__ == "__main__":
    main()