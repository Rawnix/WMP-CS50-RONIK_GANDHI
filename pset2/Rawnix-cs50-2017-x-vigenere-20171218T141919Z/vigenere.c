#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>

int main(int argc, string k[])
{
    if(argc!=2)
    {
        printf("Only one argument should be there.\n");
        return 1;
    }
    int n=strlen(k[1]);
    int key[n];
    for(int i=0; i<n; i++)
    {
        if(k[1][i]>='A' && k[1][i]<='Z') key[i] = k[1][i] - 'A';
        else if(k[1][i]>='a' && k[1][i]<='z') key[i] = k[1][i] - 'a';
        else
        {
            printf("argument should be completely alphabetic.\n");
            return 1;
        }
    }
    printf("plaintext: ");
    string s = get_string();
    int len = strlen(s);
    for(int i=0; i<len; i++)
    {
        if(isupper(s[i])) s[i] = (s[i] - 65 + key[i%n]) % 26 + 65;
        else if(islower(s[i])) s[i] = (s[i] - 97 + key[i%n]) % 26 + 97;
    }
    printf("ciphertext: %s\n", s);
    return 0;
}