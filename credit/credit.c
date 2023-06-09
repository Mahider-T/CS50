#include <stdio.h>
#include <cs50.h>

int getDigitSum(int number);
bool isValidCreditCard(long long number);
string getCardType(long long number);

int main(void) {
    long long number = get_long("Enter the credit card number: ");

    if (isValidCreditCard(number)) {
        string cardType = getCardType(number);
        printf("%s\n", cardType);
    } else {
        printf("INVALID\n");
    }

    return 0;
}

int getDigitSum(int number) {
    int sum = 0;
    while (number > 0) {
        int digit = number % 10;
        sum += digit;
        number /= 10;
    }
    return sum;
}

bool isValidCreditCard(long long number) {
    int sum = 0;
    int count = 0;

    while (number > 0) {
        int digit = number % 10;
        if (count % 2 == 0) {
            sum += digit;
        } else {
            sum += getDigitSum(digit * 2);
        }
        number /= 10;
        count++;
    }

    return (sum % 10 == 0);
}

string getCardType(long long number) {
    // American Express starts with 34 or 37 and has 15 digits
    if ((number >= 340000000000000 && number < 350000000000000) ||
        (number >= 370000000000000 && number < 380000000000000)) {
        return "AMEX";
    }
    // MasterCard starts with 51, 52, 53, 54, or 55 and has 16 digits
    else if (number >= 5100000000000000 && number < 5600000000000000) {
        return "MASTERCARD";
    }
    // Visa starts with 4 and has 13 or 16 digits
    else if ((number >= 4000000000000 && number < 5000000000000) ||
             (number >= 4000000000000000 && number < 5000000000000000)) {
        return "VISA";
    }
    // Invalid card type
    else {
        return "INVALID";
    }
}