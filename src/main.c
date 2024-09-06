// libraries needed for the program
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>



#include "Utils.h"
#include "Help.h"
#include "Encryption.h"
#include "Menu.h"
#include "Gui.h"
#include "Animations.h"
//#include "Advanced.h"









//windows function for console text size manipultation
void SetConsoleFont(int fontSize){

    // Define a CONSOLE_FONT_INFOEX structure
    CONSOLE_FONT_INFOEX cfi;
    // Set the size of the structure
    cfi.cbSize = sizeof(cfi);
    // Set the font index to 0
    cfi.nFont = 0;
    // Set the width of each character in the font (0 for automatic)
    cfi.dwFontSize.X = 0;
    // Set the height of each character in the font (in pixels) based on the parameter
    cfi.dwFontSize.Y = fontSize;
    // Specify the font family (0 for default)
    cfi.FontFamily = FF_DONTCARE;
    // Specify the font weight (400 for normal)
    cfi.FontWeight = FW_NORMAL;
    // Copy the face name of the font to be used
    wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    // Set the console font using SetCurrentConsoleFontEx
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}



// Main function
int main() {
    int choice;
    char message[1000];  
    int shift;
    bool display = 1;
    int ch, i;
    char keyword[2000];
    char filename[100];
    char input[256];
    char userText[1000];
    


 SetConsoleFont(20);

	print_logo();
  
  //main menu
    do {
    	custom_clear_screen();
    	setWhiteConsoleColor();

        box();
        gotoxy(1, 2);
        setLightGreenConsoleColor();
        printf("Select an option:\n");
        setCyanConsoleColor();
        gotoxy(1, 3);
        printf("1. $Caesar Cipher Plaintext Encryption\n");
        gotoxy(1, 4);
        printf("2. $Caesar Cipher Plaintext Decryption\n");
        gotoxy(1, 5);
        setBlueConsoleColor();
        printf("3. $Vigenere Plaintext Encryption\n");
        gotoxy(1, 6);
        printf("4. $Vigenere Plaintext Decryption\n");
        setYellowConsoleColor();
        gotoxy(1, 7);
        printf("5. $ASCII form Encryption\n");
        gotoxy(1,8);
        printf("6. $ASCII form Decryption\n");
        setPurpleConsoleColor();
        gotoxy(1,9);
        printf("7. $BINARY form Encryption  (25 character limit)\n ");
        gotoxy(1,10);
        printf("8. $BINARY form Decryption\n");
        gotoxy(1,11);
        setGrayConsoleColor();
        printf("9. $Files\n");
        setRedConsoleColor();
        gotoxy(1,12);
        printf("10. $ADVANCED E/Dcryption methods\n");
        setWhiteConsoleColor();
        gotoxy(1,13);
        printf("11. application_info - user expl");
        gotoxy(1,14);
        setLightGreenConsoleColor();
        printf("0. Exit\n");
        gotoxy(0, 18);
        setWhiteConsoleColor();
        printf("Enter your choice:$  ");
        setLightGreenConsoleColor();
        scanf(" %d", &choice);
        getchar(); // clears buffer
        
        if (choice == 1) {
	char message[1000];
	int shift;
    setWhiteConsoleColor(); 
    printf("Enter the message for Encryption:$  ");
    setLightGreenConsoleColor(); 
    fgets(message, sizeof(message), stdin); // Read the message from the user
    setWhiteConsoleColor(); 
    printf("Enter the shift for Encryption:$  ");
    setLightGreenConsoleColor(); 
    scanf("%d", &shift); 
    caesarEncrypt(message, shift); // Encrypt the message using Caesar cipher
    setWhiteConsoleColor();
    printf("Encrypted message: ");
    setLightGreenConsoleColor(); 
    printf("%s", message); 
    setWhiteConsoleColor(); 
    printf("press enter to continue");
    getchar(); // clears buffer
    while (getchar() != '\n') {
       
    }



} else if (choice == 2) {
	char message[1000];
	int shift;
    setWhiteConsoleColor(); 
    printf("Enter the message for Decryption:$  ");
    setLightGreenConsoleColor(); 
    fgets(message, sizeof(message), stdin); 
    setWhiteConsoleColor(); 
    printf("Enter the shift for Decryption:$  ");
    setLightGreenConsoleColor(); 
    scanf("%d", &shift); 
    caesarDecrypt(message, shift); // Decrypt the message using Caesar cipher
    setWhiteConsoleColor(); 
    printf("Decrypted message: ");
    setLightGreenConsoleColor(); 
    printf("%s", message); 
    setWhiteConsoleColor(); 
    printf("Press Enter to continue");
    getchar();
    while (getchar() != '\n') {
    }


}
	else if (choice == 3) {
	char message[1000],keyword[100];
					  	
    setWhiteConsoleColor(); 
    printf("Enter the message for Encryption: ");
    setLightGreenConsoleColor(); 
    fgets(message, sizeof(message), stdin); 
    setWhiteConsoleColor(); 
    printf("Enter the keyword for Vigenere encryption: ");
    setLightGreenConsoleColor(); 
    scanf("%s", keyword); 
    vigenereEncrypt(message, keyword); // Encrypt the message using Vigenere cipher
    setWhiteConsoleColor(); // Reset text color to white
    printf("Encrypted message: ");
    setLightGreenConsoleColor(); 
    printf("%s", message); 
    setWhiteConsoleColor(); 
 printf("press Enter to continue");
 getchar();
    while (getchar() != '\n') {
    }


} else if (choice == 4) {
	char message[1000], keyword[100];
    setWhiteConsoleColor(); 
    printf("Enter the message for Decryption: ");
    setLightGreenConsoleColor();
    fflush(stdin); // Flush the buffer to clear any remaining characters
    fgets(message, sizeof(message), stdin); 
    setWhiteConsoleColor(); 
    printf("Enter the keyword for Vigenere decryption: ");
    setLightGreenConsoleColor(); 
    scanf("%s", keyword); 
    vigenereDecrypt(message, keyword); // Decrypt the message using Vigenere cipher
    setWhiteConsoleColor(); 
    printf("Decrypted message: ");
    setLightGreenConsoleColor(); 
    printf("%s", message); 
    setWhiteConsoleColor(); 
    printf("press Enter to continue");
    getchar();
		while (getchar() != '\n') {
    }
} else if (choice == 5) {
	char message[1000];
    setWhiteConsoleColor();
    printf("Enter a message: ");
    setLightGreenConsoleColor(); 
    fgets(message, sizeof(message), stdin); 
    message[strcspn(message, "\n")] = '\0'; 
    setWhiteConsoleColor();
    printf("Encrypted message: ");
    setLightGreenConsoleColor(); 
    encrypt(message); // Encrypt the message
    setWhiteConsoleColor(); 
    printf("Press enter to continue");
    while(getchar() != '\n'){
		}
} else if (choice == 6) {
	char message[1000];
    
	 setWhiteConsoleColor(); 
    printf("Enter a message: ");
    setLightGreenConsoleColor(); 
    fgets(message, sizeof(message), stdin); // Read the message from the user
    message[strcspn(message, "\n")] = '\0'; 

    setWhiteConsoleColor(); 
    printf("Decrypted message: ");
    setLightGreenConsoleColor(); 
    decrypt(message); // Decrypt the message
    setWhiteConsoleColor();
    printf("press enter to cnontinue");
    while(getchar() != '\n'){
    	
		}

} else if (choice == 7) {
    char input[1000];
	setWhiteConsoleColor(); 

    printf("Enter a plaintext message: ");
    setLightGreenConsoleColor(); 
    fgets(input, sizeof(input), stdin); 

    // Remove the newline character 
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

   setWhiteConsoleColor(); 

printf("Binary representation:\n");
setLightGreenConsoleColor(); 
textToBinary(input);
setWhiteConsoleColor(); 
printf("Press enter to continue");
while(getchar()!= '\n'){
}
}else if (choice == 8) {
	char input[1000];
    setWhiteConsoleColor(); 
    printf("Enter binary data (space-separated): ");
    setLightGreenConsoleColor(); 
    fgets(input, sizeof(input), stdin);

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    setWhiteConsoleColor(); 
    printf("Text representation: ");
    setLightGreenConsoleColor(); 
    binaryToText(input); 
    setWhiteConsoleColor(); 
printf("press emter to continue");
while(getchar()!= '\n'){
}


}else if (choice == 9) {
    int subChoice;
    setCyanConsoleColor(); 
    printf("1. Encrypt or Decrypt an Existing file \n");
    setPurpleConsoleColor(); 
    printf("2. Encrypt your input and place it into a file manually (not yet available because under construction)\n");
    setWhiteConsoleColor(); 
    printf("Enter your choice below\n");
    setLightGreenConsoleColor(); 
    scanf("%d", &subChoice);
    setWhiteConsoleColor(); 
    if (subChoice == 1) {
    	char filename[100];
        setRedConsoleColor(); 
        printf("WARNING: 'The file must be in the same folder or directory as the program while running in order to find it.'\n");
        setWhiteConsoleColor(); 
        printf("Enter the filename: ");
        setLightGreenConsoleColor(); 
        scanf("%s", filename);
        setWhiteConsoleColor(); 
        char* fileContent = readFile(filename);
        int choice;
        printf("Select operation:\n");
        setBlueConsoleColor(); 
        printf("1. Encrypt\n");
        setGrayConsoleColor(); 
        printf("2. Decrypt\n");
        setWhiteConsoleColor(); 
        printf("Enter your choice: ");
        setLightGreenConsoleColor(); 
        scanf("%d", &choice);
        setWhiteConsoleColor(); 
    

    switch (choice) {
    // Encryption types menu
    case 1:
        setWhiteConsoleColor();
        printf("Select encryption type:\n");
        setCyanConsoleColor(); 
        printf("1. Caesar Cipher Encryption\n");
        setBlueConsoleColor(); 
        printf("2. Vigenere Cipher Encryption\n");
        setWhiteConsoleColor();
        printf("Enter your choice: ");
        int encryptionType;
        setLightGreenConsoleColor(); 
        scanf("%d", &encryptionType);
        setWhiteConsoleColor(); 

        switch(encryptionType) {
            case 1:
            	//int shift;
                setWhiteConsoleColor();
                printf("Enter the shift for Caesar encryption: ");
                setLightGreenConsoleColor(); 
                scanf("%d", &shift);
                setWhiteConsoleColor(); 
                caesarEncrypt(fileContent, shift);
                break;
            case 2:
            //	char keyword[1000];
                setWhiteConsoleColor();
                printf("Enter the keyword for Vigenere encryption: ");
                setLightGreenConsoleColor();
                scanf("%s", keyword);
                setWhiteConsoleColor(); 
                vigenereEncrypt(fileContent, keyword);
				break;
            default:
                setWhiteConsoleColor();
                printf("Invalid choice\n");
                free(fileContent);
                return EXIT_FAILURE;
        }
        break;

   case 2:
    setLightGreenConsoleColor(); 
    printf("Select decryption type:\n");
    setCyanConsoleColor(); 
    printf("1. Caesar Cipher Decryption\n");
    setBlueConsoleColor(); 
    printf("2. Vigenere Cipher Decryption\n");
    setWhiteConsoleColor();
    printf("Enter your choice: ");
    int decryptionType;
    setLightGreenConsoleColor(); 
    scanf("%d", &decryptionType);
    setWhiteConsoleColor(); 

    switch (decryptionType) {
        case 1:
        	//int shift;
            setWhiteConsoleColor(); 
            printf("Enter the shift for Caesar decryption: ");
            setLightGreenConsoleColor(); 
            scanf("%d", &shift);
            setWhiteConsoleColor();
            caesarDecrypt(fileContent, shift);
            break;
        case 2:
        	//char keyword[1000];
            setWhiteConsoleColor(); 
            printf("Enter the keyword for Vigenere decryption: ");
            setLightGreenConsoleColor();
            scanf("%s", keyword);
            setWhiteConsoleColor(); 
            vigenereDecrypt(fileContent, keyword);
            break;
        default:
            setWhiteConsoleColor(); 
            printf("Invalid choice\n");
            free(fileContent);
            return EXIT_FAILURE;
    }
    break;
default:
    setWhiteConsoleColor(); 
    printf("Invalid choice\n");
    free(fileContent);
    return EXIT_FAILURE;
}

writeFile(filename, fileContent);
setWhiteConsoleColor(); 
printf("Operation completed successfully.\n");
printf("press enter to continue");
getchar();
while (getchar() != '\n') {
}

} else {
    printf("Error creating or opening the file.\n");
}


}else if (choice == 11) {
    system("cls");
    setBlueConsoleColor(); 
    userhelpaboutprogram();

    system("cls");
    setWhiteConsoleColor(); 
}

else if (choice == 10) {
    setWhiteConsoleColor(); 
    char choise;
    char input[1024];
    const unsigned char aes_key[16] = "0123456789abcdef";
    unsigned char ciphertext[100];
    unsigned char decryptedtext[100];
    int ciphertext_len;
    char plaintext[1500];

    
    char messagehash[1000];

    
    //unsigned char sha256_hash[SHA256_DIGEST_LENGTH];

    // smallbox menu
    smallbox();
    gotoxy(1, 23);
    setBrightGreenConsoleColor(); 
    printf("1. $Base64 Encryption algorithm: \n ");
    gotoxy(1, 25);
    printf("2. $Base64 Decryption algorithm: \n ");
    setBrightRedConsoleColor();
    gotoxy(1, 27);
    printf("3. $AES Encryption algorithm: \n ");
    gotoxy(1, 29);
    printf("4. $AES Decryption algorithm: \n");
    setBrightMagentaConsoleColor(); 
    gotoxy(1, 31);
    printf("5. $SHA-256 hashing algorithm: \n");
    gotoxy(0, 35);
    setWhiteConsoleColor();
    printf("Enter your choice: ");
    setLightGreenConsoleColor(); 
    scanf("%c", &choise);

  

        
      getchar(); // Clear the input buffer
	 
switch (choise) {
    case '1':
        setWhiteConsoleColor();
        printf("\nEnter plaintext to encode: ");
        setLightGreenConsoleColor();
        
        fgets(input, sizeof(input), stdin);
        setWhiteConsoleColor();
        
        if (strlen(input) > 0 && input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }

        // Perform Base64 encoding
        //char* encodedData = base64encode(input, strlen(input));

        printf("\nBase64 Encoded: ");
        setLightGreenConsoleColor();
        //printf("%s \n", encodedData);
        setWhiteConsoleColor();

        // Free the allocated memory 
       // free(encodedData);
        break;
case '2':
    setWhiteConsoleColor();
    printf("\nEnter Base64 encoded string to decode: ");
    setLightGreenConsoleColor();
    
    fgets(input, sizeof(input), stdin);
    setWhiteConsoleColor();

    if (strlen(input) > 0 && input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    // Perform Base64 decoding
    //char* decodedData = base64decode(input, strlen(input));

    printf("\nBase64 Decoded: ");
    setLightGreenConsoleColor();
   // printf("%s \n", decodedData);
    setWhiteConsoleColor();

    // Free the allocated memory 
    //free(decodedData);
    break;
case '3':
    setWhiteConsoleColor();
    printf("Enter plaintext for AES encryption (up to 99 characters): ");
    setLightGreenConsoleColor();
    fgets(plaintext, sizeof(plaintext), stdin);
    setWhiteConsoleColor();

    // Remove newline character 
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }

    // Perform AES encryption
    //encryptAES((unsigned char *)plaintext, aes_key, ciphertext, &ciphertext_len);

    printf("AES Encrypted message: ");
    setLightGreenConsoleColor();
    for (int i = 0; i < ciphertext_len; ++i) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
    setWhiteConsoleColor();
    break;
case '4':
    setWhiteConsoleColor();
    printf("Enter plaintext for AES decryption (up to 99 characters): ");
    setLightGreenConsoleColor();
    fgets(plaintext, sizeof(plaintext), stdin);
    setWhiteConsoleColor();
//>>>>>>>
    size_t len_decrypt = strlen(plaintext);
    if (len_decrypt > 0 && plaintext[len_decrypt - 1] == '\n') {
        plaintext[len_decrypt - 1] = '\0';
    }

    // Perform AES decryption
    //decryptAES(ciphertext, ciphertext_len, aes_key, decryptedtext);

    printf("AES Decrypted message: ");
    setLightGreenConsoleColor();
    printf("%s", decryptedtext);
    setWhiteConsoleColor();
    printf("\n");
    break;
case '5':
    setWhiteConsoleColor();
    printf("Enter message for hashing: ");
    setLightGreenConsoleColor();

    // Use %99s to prevent buffer overflow
    if (scanf("%99s", messagehash) != 1) {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }
    // Perform SHA-256 Hashing
    //sha256Hash((const unsigned char *)messagehash, strlen(messagehash), sha256_hash);
    printf("SHA-256 Hash: ");
    setLightGreenConsoleColor();
   // for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
     //   printf("%02x", sha256_hash[i]);
    //}
    setWhiteConsoleColor();
    printf("\n");

    // Clear input buffer
    while (getchar() != '\n');
    break;
default:
    printf("Invalid choice. Exiting.\n");
    return 1;
}
printf("press enter to continue");
while(getchar()!='\n'){
}
}

}while(choice!=0);
  
displayThankYou("\n\n\n\n\n\n\n\n\n\t\t\t\t\tTHANK YOU FOR USING ENDkrypter", 50000, 1200, 3);
        
return 0;
}




