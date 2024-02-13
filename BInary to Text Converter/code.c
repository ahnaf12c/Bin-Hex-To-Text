#include<stdio.h>
#include<string.h>
#include<math.h>

#define MAX_LEN 10000  // Maximum length of the binary input string

/**
 * @brief Converts a binary string to a decimal integer.
 *
 * @param bin The binary string to be converted.
 * @return The decimal equivalent of the binary string.
 *         Returns -1 if the input is invalid.
 **/
int binaryToDecimal(char bin[])
{
    int i, j;
    int len = strlen(bin);
    int dec = 0;
    int temp;

    // Validate input length
    if (len > 8) {
        printf("Invalid value as argument!\n");
        return -1;
    }

    // Convert binary to decimal
    for (i = 0, j = len - 1; i < len; i++, j--) {
        if (bin[i] == '1') {
            temp = pow(2, j);
            dec = dec + temp;
        }
        else if (bin[i] == '0') {
            dec = dec;
        }
        else if (bin[i] != '1' && bin[i] != '0') {
            printf("Invalid value as argument!\n");
            return -1;
        }
    }
    return dec;
}

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

    printf("WELCOME TO MY BINARY TO TEXT CONVERTER!\nV ALPHA 1.5\nSTILL WORK IN PROGRESS\n\n");
    while(1) {
        // User Prompt
        printf("Please enter a string of eight bit binary numbers separated by spaces ('q' to exit): ");
        gets(bin);

        // Check for exit condition
        if (strlen(bin) == 1 && bin[0] == 'q') {
            printf("BYE! HAVE A GREAT TIME!\n");
            break;
        }

        //Processing the binary input
        for (i = 0, j = 0; i < strlen(bin); i++) {
            if (bin[i] != ' ') {
                binTemp[j] = bin[i];
                j++;
            }
            else if (j > 0) {
                binTemp[j] == '\0';
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

//Main Function
int main()
{
    binToText();
    return 0;
}
