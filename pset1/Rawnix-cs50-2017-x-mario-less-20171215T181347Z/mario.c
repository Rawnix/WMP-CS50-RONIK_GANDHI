#include<stdio.h>
#include<cs50.h>

void printSpaces(int n)
{
    for(int i=0; i<n; i++)
    {
        printf(" ");
    }
}

int main(void)
{
    int h;
    do
    {
        printf("Height: ");
        h = get_int();
    }while(h<0 || h>23);
    int spaces = h-1;
    for(int i=0; i<h; i++)
    {
        printSpaces(spaces);
        spaces--;
        for(int j=0; j<i+2; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}