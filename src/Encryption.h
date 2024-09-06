#ifndef ENCRYPTION_H
#define ENCRYPTION_H


void caesarEncrypt(char *text, int shift);
void caesarDecrypt(char *text, int shift);
void textToBinary(const char *text);
void binaryToText(const char *binary);
void encrypt(char *message);
void decrypt(char *message);
char* readFile(const char* filename);
void writeFile(const char* filename, const char* content);
void vigenereEncrypt(char *text, char *keyword);
void vigenereDecrypt(char *text, char *keyword);

#endif
