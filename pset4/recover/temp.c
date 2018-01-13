#include<stdio.h>

int main(void)
{
    printf("%d\n", (11110000&00001111));
    printf("%d\n", (11110000&11110000));
    printf("%d\n", (00000010&00000010));
    printf("%d\n", (00000101&00000110));
    if((0xea & 240)==224)
    {
        printf("true\n");
    }
    printf("%03d\n", 0);
    return 0;
}