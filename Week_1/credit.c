#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt user for input
    long num;
    do
    {
        num = get_long("Number: ");
    }
    while (num < 0); //only proceed when the digit > 0


    //calculate checksum using Luhn's algo
    //select alternate number, starting from second last and multiply each by 2
    int even1, even2, even3, even4, even5, even6, even7, even8, sum1, sum2, sum3;

    even1 = ((num % 100) / 10) * 2;
    even2 = ((num % 10000) / 1000) * 2;
    even3 = ((num % 1000000) / 100000) * 2;
    even4 = ((num % 100000000) / 10000000) * 2;
    even5 = ((num % 10000000000) / 1000000000) * 2;
    even6 = ((num % 1000000000000) / 100000000000) * 2;
    even7 = ((num % 100000000000000) / 10000000000000) * 2;
    even8 = ((num % 100000000000000000) / 1000000000000000) * 2;

    //split the digit again if there are any with 2 digits
    even1 = ((even1 % 100) / 10) + (even1 % 10);
    even2 = ((even2 % 100) / 10) + (even2 % 10);
    even3 = ((even3 % 100) / 10) + (even3 % 10);
    even4 = ((even4 % 100) / 10) + (even4 % 10);
    even5 = ((even5 % 100) / 10) + (even5 % 10);
    even6 = ((even6 % 100) / 10) + (even6 % 10);
    even7 = ((even7 % 100) / 10) + (even7 % 10);
    even8 = ((even8 % 100) / 10) + (even8 % 10);

    //sum all the evens tgt
    sum1 = even1 + even2 + even3 + even4 + even5 + even6 + even7 + even8;

    //digits that were not multiplied by 2
    int odd1, odd2, odd3, odd4, odd5, odd6, odd7, odd8;

    odd1 = (num % 10);
    odd2 = ((num % 1000) / 100);
    odd3 = ((num % 100000) / 10000);
    odd4 = ((num % 10000000) / 1000000);
    odd5 = ((num % 1000000000) / 100000000);
    odd6 = ((num % 100000000000) / 10000000000);
    odd7 = ((num % 10000000000000) / 1000000000000);
    odd8 = ((num % 1000000000000000) / 100000000000000);

    //sum add the odds tgt
    sum2 = odd1 + odd2 + odd3 + odd4 + odd5 + odd6 + odd7 + odd8;

    //sum of odds and evens
    sum3 = sum1 + sum2;

    //if sum3 last digit is not 0 = invalid
    if (sum3 % 10 != 0)
    {
        printf("%s\n", "INVALID");
        return 0;
    }

    //check which card by length and starting digits

    int length = 0;
    long amex = num;
    long mastercard = num;
    long visa = num;

    //get length
    while (num > 0)
    {
        num /= 10;
        length++;
    }

    //AMEX
    while (amex >= 10000000000000)
    {
        amex /= 10000000000000;
    }
    if ((amex == 34 || amex == 37) && length == 15)
    {
        printf("%s\n", "AMEX");
        return 0;
    }

    //MASTERCARD
    while (mastercard >= 100000000000000)
    {
        mastercard /= 100000000000000;
    }
    if ((mastercard == 51 || mastercard == 52 || mastercard == 53 || mastercard == 54 || mastercard == 55) && length == 16)
    {
        printf("%s\n", "MASTERCARD");
        return 0;
    }

    //VISA
    while (visa >= 10)
    {
        visa /= 10;
    }
    if (visa == 4 && (length == 13 || length == 16))
    {
        printf("%s\n", "VISA");
        return 0;
    }
    else
    {
        printf("%s\n", "INVALID");
        return 0;
    }
}

