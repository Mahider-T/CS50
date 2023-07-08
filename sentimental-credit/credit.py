# TODO
from cs50 import get_int, get_string
import sys
def getDigitSum(number):
    sum = 0
    value = str(number)
    for numbers in value:
        sum += int(numbers)
    return sum
    # for
    # while(number > 0):
    #     sum += int(number % 10)
    #     number /= 10
    # return sum
def isValidCreditCard(number):
    empty = []
    # print(empty)
    string = str(number)
    for numbers in string:
        empty.append(int(numbers))
    # print(empty)
    # print(len(empty))
    if len(empty) != 13 and len(empty) != 15 and len(empty) != 16:
        return False

    sum = 0
    count = 0
    for digit in range(len(empty) - 1, -1, -1):
        # print(digit)
        if count % 2 == 0:
            sum += empty[digit]
        else:
            # print(empty[digit])
            new = 2 * empty[digit]
            sum += getDigitSum(new)

        count += 1
    # print(sum)
    if(sum % 10 == 0):
        return True
    return False


# def getCardType():

def main():
    card = get_string("Enter the credit card number: ")
    empty = []
    # print(empty)
    # string = str(card)
    print(isValidCreditCard(card))
    if isValidCreditCard(card) != True:
        print("INVALID")
        sys.exit()
    for numbers in card:
        empty.append(int(numbers))

    if len(empty) == 15 and empty[0] == 3 and  (empty[1] == 4 or empty[1] == 5 or empty[1] == 7 or empty[1] == 8):
        print("AMEX")
    if len(empty) == 13 or len(empty) == 16 and (empty[0] == 4):
        print("VISA")
    if len(empty) == 16 and empty[0] == 5 and (empty[1] == 1 or empty[1] == 6) :
        print("MASTERCARD")


if __name__ == "__main__":
    main()