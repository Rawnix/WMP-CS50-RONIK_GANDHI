#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<cs50.h>

int main(int argc, string keys[])
{
    if(argc == 2)
    {
        int key = atoi(keys[1]);
        if(key>=0)
        {
            printf("plaintext: ");
            string a = get_string();
            for(int i=0, n=strlen(a); i<n; i++)
            {
                if(isalpha(a[i]))
                {
                    if(a[i]<91) a[i] = (a[i]-65+key)%26+65;
                    else a[i] = (a[i]-97+key)%26+97;
                }
            }
            printf("ciphertext: %s\n", a);
            return 0;
        }
        else
        {
            printf("Key should be non-negative.\n");
            return 1;
        }
    }
    printf("Only one non negative argument should be there.\n");
    return 1;
}