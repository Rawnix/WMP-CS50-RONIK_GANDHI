#include<stdio.h>
#include<math.h>
#include<cs50.h>

int main(void)
{
    int coins=0, temp;
    double amt;
    printf("O hai! ");
    do
    {
        printf("How much change I owed?\n");
        amt = get_double();
    }while(amt<0);
    amt = round(amt*100);
    if(amt>=25)
    {
        temp = (int)(amt / 25);
        amt -= 25*(double)temp;
        coins += temp;
        //printf("%d 25c left: %lf\n", temp, amt);
    }
    if(amt>=10)
    {
        temp = (int)(amt / 10);
        amt -= 10*(double)temp;
        coins += temp;
        //printf("%d 10c left: %lf\n", temp, amt);
    }
    if(amt>=5)
    {
        temp = (int)(amt / 5);
        amt -= 5*(double)temp;
        coins += temp;
        //printf("%d 05c left: %lf\n", temp, amt);
    }
    if(amt>=1)
    {
        temp = (int)(amt / 1);
        amt -= 1*(double)temp;
        coins += temp;
        //printf("%d 01c left: %lf\n", temp, amt);
    }
    printf("%i\n", coins);
    return 0;
}