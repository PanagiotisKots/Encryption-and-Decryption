#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

#include "Utils.h"





// Function to set the cursor position 
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


// Function for a small box
void smallbox() {
    int i;
    char ch;
    //  top left corner of the box
    ch = 201;
    gotoxy(0, 22);
    printf("%c", ch);
    //top border of the box
    ch = 205;
    for (i = 1; i < 50; i++) {
        gotoxy(i, 22);
        printf("%c", ch);
    }
    //top right corner of the box
    ch = 187;
    gotoxy(50, 22);
    printf("%c", ch);
    // side borders of the box
    ch = 186;
    for (i = 23; i < 33; i++) {
        gotoxy(0, i);
        printf("%c", ch);
        gotoxy(50, i);
        printf("%c", ch);
    }
    //bottom left corner of the box
    ch = 200;
    gotoxy(0, 33);
    printf("%c", ch);
    //bottom border of the box
    ch = 205;
    for (i = 1; i < 50; i++) {
        gotoxy(i, 33);
        printf("%c", ch);
    }
    // bottom right corner of the box
    ch = 188;
    gotoxy(50, 33);
    printf("%c", ch);
}







// Function to draw the box on the console
void box() {
    int i;
    char ch;
    // Top of the box
    ch = 201; // Corner for the top left
    gotoxy(0, 1);
    printf("%c", ch);
    for (i = 1; i < 80; i++) {
        ch = 205; 
        gotoxy(i, 1);
        printf("%c", ch);
    }
    ch = 187; // Corner for the top right
    gotoxy(80, 1);
    printf("%c", ch);
    // Vertical borders of the box
    ch = 186; 
    for (i = 2; i < 16; i++) {
        gotoxy(0, i);
        printf("%c", ch);
        gotoxy(80, i);
        printf("%c", ch);
    }
    // Bottom border of the box
    ch = 200; // Corner for the bottom left
    gotoxy(0, 16);
    printf("%c", ch);
    for (i = 1; i < 80; i++) {
        ch = 205; 
        gotoxy(i, 16);
        printf("%c", ch);
    }
    ch = 188; // Corner for the bottom right
    gotoxy(80, 16);
    printf("%c", ch);
}

// Clear screen function
void custom_clear_screen() {
    int rows = 125; 
    int cols = 45;  
    int i, j;
    // Loop through each row and column starting from column 18
    for (i = 0; i < rows; i++) {
        for (j = 18; j < cols; j++) {
            gotoxy(i, j); // Set the cursor position using the gotoxy function for clearing the character
            printf(" ");  // Print a space to clear the character at the current position
        }
    }
}


void display_description() {
    int i;
    char description[] = "Welcome to ENDkrypter - Your Ultimate Encryption and Decryption Tool\n"
                          "\nENDkrypter is a versatile and user-friendly encryption and decryption program designed to safeguard your sensitive data. Whether you need to protect confidential messages or decrypt encoded information, ENDkrypter has you covered.\n"
                          "\nKey Features:\n"
                          "1.  Cipher Encryption and Decryption: Basic yet effective encryption method.\n"
                          "2. Vigenere Cipher Encryption and Decryption: Enhanced security with a keyword-based approach.\n"
                          "3. Base64 an encoding algorithm that transforms binary data into a human-readable ASCII format, making it suitable for transmission over text-based protocols .\n"
                          "4. Advanced Encryption Protocol: Robust encryption algorithms for heightened security.\n"
                          "5. File Encryption and Decryption: Encrypt and decrypt entire files with ease.\n"
                          "6. SHA256 Hashing: Generate secure hash values for data integrity verification.\n"
                          "7. Binary data encoding: The process of representing data in a binary format, that can be easily processed by computers.\n"
                          "8. ASCII (American Standard Code for Information Interchange) encoding represents characters using numeric values, specifically 7-bit integers\n"
                          "\nHow ENDkrypter Can Be Useful:\n"
                          " - Secure Communication: Encrypt your messages to ensure privacy during communication.\n"
                          " - Data Protection: Safeguard sensitive files and data from unauthorized access.\n"
                          " - Information Integrity: Verify the integrity of your data using SHA256 hashing.\n"
                          " - Versatile Encryption: Choose from various encryption methods based on your security needs.\n"
                          " - File Security: Encrypt and decrypt entire files seamlessly for enhanced confidentiality.\n"
                          "\n"
                          "\nInstructions:\n"
                          "1. Choose an option from the menu by entering the corresponding number.\n"
                          "2. Follow the prompts to input your data and key information.\n"
                          "3. Retrieve encrypted or decrypted results securely.\n"
                          "\nYour data security is our top priority. Enjoy the peace of mind that comes with ENDkrypter.\n"
                          "\nPress Enter to continue...\n";
                          //add 
    for (i = 0; description[i] != '\0'; i++) {
        printColoredChar(description[i], FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    }
  
    while (getchar() != '\n') {
		}
}



// Function to display loading dots for the "Loading"
void loadingdots() {
    int loading_dot, a;
    int d = 600;
    printf("\n\n\n\n\n\n\n\n\n\t\t\tENDkrypter session starting!!!"); 
    // Display loading dots animation
    for (loading_dot = 0; loading_dot < 7; loading_dot++) {
        a = loading_dot;
        printf("."); // Display a loading dot
        Sleep(d); // Introduce a delay between loading dots
    }
}

