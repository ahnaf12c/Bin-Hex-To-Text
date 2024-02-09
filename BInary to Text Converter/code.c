#include<stdio.h>
#include<string.h>
#include<math.h>

int binaryToDecimal(char bin[])
{
    int i, j;
    int len = strlen(bin);
    int dec = 0;
    int temp;

    if (len > 8) {
        printf("Invalid value as argument!\n");
        return 1;
    }

    for (i = 0, j = len - 1; i < len; i++, j--) {
        if (bin[i] == '1') {
            temp = pow(2, j);
            dec = dec + temp;
        }
        else if (bin[i] == '0') {
            dec = dec;
        }
        else if (bin[i] != '1' || bin[i] != '0') {
            printf("Invalid value as argument!\n");
            return 1;
        }
    }
    return dec;
}



int main()
{
    char bin[9];

    printf("WELCOME TO MY BINARY TO TEXT CONVERTER!\n V ALPHA 1.0\nSTILL WORK IN PROGRESS\n\n");
    while(1) {
        printf("Please enter an eight bit binary number (0 to exit): ");
        gets(bin);
        if (strlen(bin) == 1 && bin[0] == '0') {
            printf("BYE! HAVE AGREAT TIME!\n");
            break;
        }
        int dec = binaryToDecimal(bin);
        char ch = dec;
        printf("%c\n", ch);
    }
    return 0;
}
