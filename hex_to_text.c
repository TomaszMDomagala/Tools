#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hexToText(const char *hexString)
{
    int len = strlen(hexString);

    if (len % 2 != 0) {
        printf("Invalid hex string length. \n");
        return;
    }

    char *text = (char *)malloc(len / 2 + 1);

    if (text == NULL) {
        printf("Memory allocation failed. \n");
        return;
    }

    int j = 0;
    for (int i = 0; i < len; i += 2) {
        char hex[3];
        strncpy(hex, &hexString[i], 2);
        hex[2] = '\0';

        int num = strtol(hex, NULL, 16);
        text[j++] = (char)num;
    }

    text[j] = '\0';
    printf("Converted hax value is: %s\n", text);

    free(text);
}

int main(int argc, char *argv[]) {
    if (argc == 2)
    {
        char *hexString = argv[1];
        hexToText(hexString);
    } 
    else if (argc == 1)
    {
        char hexString[100];
        printf("Enter hexadecimal string: ");
        scanf("%s", hexString);
        hexToText(hexString);
    }
    else
    {
        printf("Usage: \n");
        printf("To input hex string as argument: %s <hex_string> \n", argv[0]);
        printf("To input hex stringinteractively: %s \n", argv[0]);
        return 1;
    }

    return 0;
}