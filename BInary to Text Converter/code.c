#include<stdio.h>
#include<string.h>
#include<math.h>

int binaryToDecimal(char bin[])
{
    int i, j;
    int len = strlen(bin);
    int dec = 0;
    int temp;

    for (i = 0, j = len - 1; i < len; i++, j--) {
        if (bin[i] == '1') {
            temp = pow(2, j);
            dec = dec + temp;
        }
        else if (bin[i] == '0') {
            dec = dec;
        }
        else {
            printf("Invalid value as argument!\n");
            return 1;
        }
    }
    return dec;
}



int main()
{
    char bin[9];
    gets(bin);
    int dec = binaryToDecimal(bin);
    char ch = dec;    
    printf("%c\n", ch);
    return 0;
}
