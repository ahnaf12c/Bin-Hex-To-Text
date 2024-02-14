#include<stdio.h>
#include<string.h>
#include<math.h>
#include"binHex.h"

#define MAX_LEN 10000  // Maximum length of the binary input string

/**
 * @brief Converts binary input to text.
 *
 * Reads a string of eight-bit binary numbers separated by spaces from the user,
 * converts each group of eight bits to its corresponding ASCII character,
 * and prints the resulting text.
 */
void binToText()
{
    char bin[MAX_LEN], binTemp[9], ch;
    int dec;
    int i, j;

    while(1) {
        // User Prompt
        printf("Please enter a string of eight bit binary numbers separated by spaces ('q' to exit): ");
        gets(bin);

        // Check for exit condition
        if (strlen(bin) == 1 && bin[0] == 'q') {
            printf("Exiting BinToText. . .\n\n");
            break;
        }

        //Processing the binary input
        for (i = 0, j = 0; i < strlen(bin); i++) {
            if (bin[i] != ' ') {
                binTemp[j] = bin[i];
                j++;
            }
            else if (j > 0) {
                //binTemp[j] == '\0';
                dec = binaryToDecimal(binTemp);
                if (dec == -1) {
                    break;
                }
                else if (dec > 0){
                    ch = dec;
                    printf("%c", ch);
                }
                j = 0;
            }
        }

        //Print remaining characters
        if (j > 0) {
            binTemp[j] = '\0';
            dec = binaryToDecimal(binTemp);
            if (dec > 0) {
                ch = dec;
                printf("%c", ch);
            }
        }

        printf("\n");
    }
}

/**
 * @brief Converts hexadecimal input to text.
 *
 * Reads a string of 2 digits hexadecimal numbers separated by spaces from the user,
 * converts each group of 2 digits to its corresponding ASCII character,
 * and prints the resulting text.
 */
void hexToText()
{
    char hex[MAX_LEN], hexTemp[9], ch;
    int dec;
    int i, j;

    while(1) {
        // User Prompt
        printf("Please enter a string of 2 digit hex numbers separated by spaces ('q' to exit): ");
        gets(hex);

        // Check for exit condition
        if (strlen(hex) == 1 && hex[0] == 'q') {
            printf("Exiting HexToText. . .\n\n");
            break;
        }

        //Processing the hex input
        for (i = 0, j = 0; i < strlen(hex); i++) {
            if (hex[i] != ' ') {
                hexTemp[j] = hex[i];
                j++;
            }
            else if (j > 0) {
                hexTemp[j] == '\0';
                dec = hexToDec(hexTemp);
                if (dec == -1) {
                    break;
                }
                else if (dec > 0){
                    ch = dec;
                    printf("%c", ch);
                }
                j = 0;
            }
        }

        //Print remaining characters
        if (j > 0) {
            hexTemp[j] = '\0';
            dec = hexToDec(hexTemp);
            if (dec > 0) {
                ch = dec;
                printf("%c", ch);
            }
        }

        printf("\n");
    }
}
