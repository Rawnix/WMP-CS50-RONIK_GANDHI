#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
    char* a;
    int flag=0, wasSpace=1;
    a = get_string();
    for(int i=0;i<strlen(a)&&flag<3;i++)
    {
        if(a[i]==' ')
        {
            wasSpace=1;
            continue;
        }
        else if(wasSpace)
        {
            if(a[i]>96) printf("%c", a[i]-32);
            else printf("%c", a[i]);
            flag++;
            wasSpace=0;
        }
    }
    printf("\n");
    return 0;
}