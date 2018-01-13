#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    if(argc!=2)
    {
        printf("only 2 arguments.\n");
        return 1;
    }
    string hash = argv[1];

    char salt[2] = { hash[0], hash[1] };

    char alphabets[54];

    alphabets[0] = '\0';
    for(int i=1; i<27; i++)
    {
        alphabets[i] = (char)(64+i);
    }
    for(int i=27; i<53; i++)
    {
        alphabets[i] = (char)(70+i);
    }
    alphabets[53] = '\0';

    char pswd[5];
    pswd[4] = '\0';

    for(int i=0; i<53; i++)
    {
        for(int j=0; j<53; j++)
        {
            for(int k=0; k<53; k++)
            {
                for(int l=0; l<53; l++)
                {
                    pswd[0] = alphabets[i];
                    pswd[1] = alphabets[j];
                    pswd[2] = alphabets[k];
                    pswd[3] = alphabets[l];

                    if(strcmp(hash, crypt(pswd, salt)) == 0)
                    {
                        printf("%s\n", pswd);
                        return 0;
                    }
                }
            }
        }
    }

}