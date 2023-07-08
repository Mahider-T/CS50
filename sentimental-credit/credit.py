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
    if(len(empty) != 13 or len(empty) != 15 or len(empty) != 16 ):
        return False
    sum = 0
    count = 0
    for digit in range(len(empty), -1, -1):
        if(count % 2 == 0):
            sum += empty[digit]
        # else:
        #     sum += 2*empty[digit]
        count += 1
    return sum

    # if(sum % 10 == 0):
    #     return True
    # return False


    # print(empty)

# def getCardType():

def main():
    card = get_string("Enter the credit card number: ")
    print(isValidCreditCard(card))




if __name__ == "__main__":
    main()