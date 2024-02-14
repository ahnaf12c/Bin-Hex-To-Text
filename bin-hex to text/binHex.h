#include<stdio.h>
#include<string.h>
#include<math.h>

#define MAX_LEN_BIN 8  // Maximum length of each section of the binary input string
#define MAX_LEN_HEX 2  // Maximum length of each section of the hexadecimal input string


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
    if (len > MAX_LEN_BIN) {
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
 * @brief Converts a hexadecimal string to a decimal integer.
 *
 * @param hex The hexadecimal string to be converted.
 * @return The decimal equivalent of the hexadecimal string.
 *         Returns -1 if the input is invalid.
 **/
int hexToDec(char hex[])
{
    int i, j;
    int len = strlen(hex);
    int dec = 0;
    int temp, temp2;

    // Validate input length
    if (len > MAX_LEN_HEX) {
        printf("Invalid value as argument!\n");
        return -1;
    }

    for (i = 0, j = len - 1; i < len; i++, j--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            temp2 = hex[i] - 48;
            temp = temp2 * pow(16, j);
            dec = dec + temp;
        }

        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            temp2 = hex[i] - 55;
            temp = temp2 * pow(16, j);
            dec = dec + temp;
        }
        else {
            printf("Invalid value as argument!\n");
            return -1;
        }
    }
    return dec;
}
