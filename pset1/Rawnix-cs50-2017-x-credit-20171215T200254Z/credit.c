#include<stdio.h>
#include<math.h>
#include<cs50.h>

long long num;

int func(int n)     //returns the sum of digits of the product of 2 and n.
{
    switch(n)
    {
        case 0: return 0;
        case 1: return 2;
        case 2: return 4;
        case 3: return 6;
        case 4: return 8;
        case 5: return 1;
        case 6: return 3;
        case 7: return 5;
        case 8: return 7;
        case 9: return 9;
        default: return -1;
    }
}

int checksum(int d) //d is the odd number just >= the number of digits in card number
{
    int sum=0;
    for(int i=d;i>0;i-=2)
    {
        sum += func((int)(num/pow(10,i)));
        num -= (int)(num/pow(10,i))*pow(10,i);
        sum += (int)(num/pow(10,i-1));
        num -= (int)(num/pow(10,i-1))*pow(10,i-1);
    }
    if(!(sum & 1)) return 1;
    else return 0;
}

int main(void)
{

    printf("Number: ");
    num = get_long_long();
    if(num>3999999999999 && num<5000000000000)  //check for visa-13
    {
        if(checksum(13))
            printf("VISA\n");
        else printf("INVALID\n");
    }
    else if((num>339999999999999 && num<350000000000000) || (num>369999999999999 && num<380000000000000))   //check for amex
    {
        if(checksum(15)) printf("AMEX\n");
        else printf("INVALID\n");
    }
    else if(num>5099999999999999 && num<5600000000000000)   //check for mastercard
    {
        if(checksum(17)) printf("MASTERCARD\n");
        else printf("INVALID\n");
    }
    else if(num>3999999999999999 && num<5000000000000000)   //check for visa-16
    {
        if(checksum(17)) printf("VISA\n");
        else printf("INVALID\n");
    }
    else printf("INVALID\n");

    return 0;
}