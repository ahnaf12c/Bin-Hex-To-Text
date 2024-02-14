#include<stdio.h>
#include<string.h>
#include<math.h>
#include"convert.h"

#define MAX_LEN 10000  // Maximum length of the binary input string

//Main Function
int main()
{
    char comd[10];
    printf("WELCOME TO MY BIN/HEX TO TEXT CONVERTER!\nV FULL RELEASE 1.0\n\n");
    while (1) {
        printf("Please Enter a command ('h' for help): ");
        gets(comd);
        int len = strlen(comd);

        if (strcmp(comd, "h") == 0) {
            printf("List of Commands:\n");
            printf("'h' for help\n");
            printf("'bt' to enter binary to text converter.\n");
            printf("'ht' to enter hex to text converter.\n");
            printf("'.q' to exit.\n\n");
        }
        else if (strcmp(comd, ".q") == 0) {
            printf("Thanks For using!\nExiting. . .\n");
            break;
        }
        else if (strcmp(comd, "bt") == 0) {
            printf("\nEntering BinToText converter. . .\n");
            binToText();
        }
        else if (strcmp(comd, "ht") == 0) {
            printf("\nEntering HexToText converter. . .\n");
            hexToText();
        }
    }
    return 0;
}
