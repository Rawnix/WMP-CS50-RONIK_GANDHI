#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
    char* a;
    int flag=0;
    a = get_string();
    if(a[0]>96) printf("%c", a[0]-32);
    else printf("%c", a[0]);
    for(int i=1;i<strlen(a)&&flag<2;i++)
    {
        if(a[i]==' ')
        {
            if(a[i+1]>96) printf("%c", a[i+1]-32);
            else printf("%c", a[i+1]);
            flag++;
        }
    }
    printf("\n");
    return 0;
}