// libraries needed for the program
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>




#include "Encryption.h"


// Function to encrypt a message using Caesar cipher
void caesarEncrypt(char *text, int shift) {
    while (*text) {
        if (isalpha(*text)) {
            if (isupper(*text)) {
                *text = ((*text - 'A' + shift) % 26) + 'A'; 
            } else {
                *text = ((*text - 'a' + shift) % 26) + 'a'; 
            }
        }
        text++;
    }
}


// Function to decrypt a message using the Caesar cipher
void caesarDecrypt(char *text, int shift) {
    caesarEncrypt(text, -shift); 
}











// Function to convert text to binary representation
void textToBinary(const char *text) {
    size_t len = strlen(text);
    int i, j;

    for (i = 0; i < len; ++i) {
        char currentChar = text[i];

        // Convert character to binary 
        for (j = 7; j >= 0; --j) {
            putchar((currentChar & (1 << j)) ? '1' : '0');
        }
        putchar(' '); 
    }
    printf("\n");
}



// Function to convert binary to text representation
void binaryToText(const char *binary) {
    size_t len = strlen(binary);
    int i;

    for (i = 0; i < len; i += 9) { // packs 
        if (binary[i] == ' ') {
            continue; 
        }
        char byte[9];
        strncpy(byte, &binary[i], 8);
        byte[8] = '\0';
        // Convert 
        char character = (char)strtol(byte, NULL, 2);
        putchar(character);
    }
    printf("\n");
}



// Function for encrypting a message using imple ascii
void encrypt(char *message) {
    while (*message) {
        if ((*message >= 'a' && *message <='z') || (*message >= 'A'&& *message <= 'Z')) {
            printf("%d ", *message);
        } else {
            printf("%c ",  *message); 
        }
        message++;
    }
    printf("\n");
}




// decrypting
void decrypt(char *message) {
    while (*message) {
        if (*message == ' ') {
            printf(" "); 
        } else {
            int ascii_code = 0;
            while (*message != ' ' && *message) {
                ascii_code = ascii_code * 10 + (*message - '0');
                message++;
            }
            printf("%c", (char)ascii_code); 
        }
        if (*message) {
            message++;
        }
    }
    printf("\n");
}








// Function for reading the content of a file 
char* readFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error occurred opening the file");
        exit(EXIT_FAILURE);
    }
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* content = (char*)malloc(length + 1);
    if (!content) {
        perror("Memory allocation error occurred");
        exit(EXIT_FAILURE);
    }
    fread(content, 1, length, file);
    fclose(file);
    content[length] = '\0';
    
    return content;
}


// Function for writing to a file
void writeFile(const char* filename, const char* content) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s", content);
    fclose(file);
}

// Encryption using the Vigenere cipher
void vigenereEncrypt(char *text, char *keyword) {
    int i;
    int keyLen = strlen(keyword);
    int textLen = strlen(text);

    for (i = 0; i < textLen; i++) {
        if (isalpha(text[i])) {
            int keywordIndex = i % keyLen;
            int shift = tolower(keyword[keywordIndex]) -'a';

            if (isupper(text[i])) {
                text[i] = 'A'+ (text[i] - 'A' + shift) % 26;
            } else {
                text[i] ='a' + (text[i] - 'a'+ shift) % 26;
            }
        }
    }
}

// Decryption using the Vigenere cipher
void vigenereDecrypt(char *text, char *keyword) {
    int i;
    int keyLen = strlen(keyword);
    int textLen = strlen(text);

    for (i = 0; i < textLen; i++) {
        if (isalpha(text[i])) {
            int keywordIndex = i % keyLen;
            int shift = tolower(keyword[keywordIndex]) - 'a';
            
            if (isupper(text[i])) {
                text[i] = 'A' + (text[i] - 'A' - shift + 26) % 26;
            } else {
                text[i] = 'a' + (text[i] - 'a' - shift + 26) % 26;
            }
        }
    }
}


