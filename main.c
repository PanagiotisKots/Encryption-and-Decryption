// libraries needed for the program
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include <openssl/rand.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/sha.h>
#define BUFFER_SIZE MAX



// Function to display text slowly 
void display_text_slowly_des(const char *text, int delay) {
    for (const char *c = text; *c != '\0'; ++c) {
        // Print the current character
		putchar(*c);
		// Flush the standard output 
        fflush(stdout);  
        //  delay for animetion
        Sleep(10);        
		 }
    printf("\nPress Enter to continue...\n");     
    while (getchar() != '\n'); // Wait for the user to press Enter
}



void displayThankYou(const char *message, int delayBetweenChars, int loadingDotsDelay, int numLoadingDots) {
    int i, loading_dot;

    // Display the message 
    for (i = 0; message[i] != '\0'; i++) {
    	// Display the character of the message
        putchar(message[i]); 
        // Flush the buffer 
        fflush(stdout); 
        // delay between characters
        usleep(delayBetweenChars); 
}
    // Display loading dots
    for (loading_dot = 0; loading_dot < numLoadingDots; loading_dot++) {
        printf("."); 
        // Flush the buffer for immediate display
        fflush(stdout);
		 //delay between loading dots
        Sleep(loadingDotsDelay); 
    }
}



//program info-user helper
void userhelpaboutprogram() {
    int choice;
    //loop
    do{
    
    setRedConsoleColor();
    printf("Welcome to the ENDkrypters user manual!\n");
    
    setPurpleConsoleColor();
    char username[50];
    printf("\nChoose a method to learn more about it and how to use it:\n");
    
    setBlueConsoleColor();
    printf("___________________________________________________________\n");
    printf("\n1. Caesar Cipher encryption method\n");
    printf("\n2. Vigenere Cipher encryption method\n");
    printf("\n3. Ascii encryption method\n");
    printf("\n4. Binary encryption method \n");
    printf("\n5. Base64 encryption method \n");
    printf("\n6. Aes encryption method \n");
    printf("\n7. SHA-256 encryption method \n");
    printf("\n0. To exit\n");
    printf("____________________________________________________________\n");

    setWhiteConsoleColor();
    printf("\n");
    printf("Enter the number corresponding to your choice: ");
    
    setLightGreenConsoleColor();
    scanf("%d", &choice);
    
    setWhiteConsoleColor();
    //info
    char caesardes[]= "The Caesar Cipher, an ancient cryptographic gem, is a splendid example of simplicity and elegance in the realm of encryption.\n"
                      "Picture a scroll from the days of Caesar, carrying secret messages across the vast expanses of the Roman Empire\n"
                      "At its core, the Caesar Cipher employs a timeless technique - the art of letter shifting\n"
                      "In this enchanting method, each letter of the plaintext is gracefully transposed along the alphabet, creating a dance of secrecy. \n"
                      "The key, a magical number known only to the sender and recipient, determines the magnitude and direction of this enchanting shift.\n "
                      "A positive key transports the letters forward, while a negative key beckons them backward in a rhythmic procession.\n"
                      "The process unfolds like a poetic melody. A 'A' may metamorphose into a 'D,' a 'C' may waltz into an 'F,' and so the dance continues until the entire message is adorned in a veil of secrecy.\n"
                      "It's a ballet of characters, an encrypted symphony that guards the essence of communication.\n"
                      "Mathematically, if 'P' represents the plaintext character and 'K' is the key (an integer representing the shift), the ciphertext 'C' is calculated as:\n"
                      "C�%(P+K)mod26 ... mod 26' ensures that the shift wraps around the alphabet. \n"
                      "\nIts usage is as it follows:\n"
                      "\n1. Select Caesar copher encryption 'case 1' and then enter the plaintext for it to encrypt, after you are given the choise to\n"
                      "select number of places for it to move and encrypt the plaintext.\n";



    char vigeneredes[]= "The Vigenère Cipher, a captivating masterpiece in the world of classical cryptography, elevates the art of encryption to a polyalphabetic symphony.\n"
                        "Named after the French cryptographer Blaise de Vigenère, this method weaves a tapestry of complexity by employing \n"
                        "multiple Caesar Ciphers in harmonious coordination.\n"
                        "Envision the dance of letters across the plaintext, not bound by a single Caesar's stride, but guided by a symphony of keys \n"
                        "- a melodic progression that transforms each character into a note in an encrypted sonnet.\n"
                        "The key, a rhythmic sequence of letters, dictates the shifting pattern for each letter of the message\n"
                        "creating a mesmerizing polyalphabetic encryption ballet.\n"
                        "The beauty lies in the complexity woven into the fabric of the Vigenère Cipher. Unlike its simpler Caesar cousin, \n"
                        "here each letter may take on a myriad of transformations, influenced by the sequential notes of the key. \n"
                        "A 'C' might become an 'F' when serenaded by one key, yet a 'C' might elegantly transform into a 'G' under the enchantment of another.\n"
                        "Given a plaintext character PiPi​, key character KiKi​, and alphabet size mm, the encryption formula is:\n"
                        "Ci​≡(Pi​+Ki​)mod m....  The key is repeated cyclically to match the length of the plaintext\n"
                        "\n Its usage is as it follows:\n"
                        "\n 1. Select Vigenere cipher encryption method from the programs starting menu and then write your plaintext for encryption.\n"
                        "Then enter the secret phrase (key) for it to use for the plaintext encryption.";


char Asciides[]= "ASCII (American Standard Code for Information Interchange), developed in the early 1960s\n"
                "emerged as a standardized character encoding system for early computers. Its roots lie in telegraph code and character sets used by teletypewriters.\n"
                "ASCII encodes characters into 7 or 8 bits, allowing representation of up to 128 or 256 unique characters. \n"
                "It includes letters, numerals, punctuation, and control characters, providing a universal language for digital communication.\n"
                "Each character is assigned a unique numerical value, typically 7-bit or 8-bit binary codes. \n"
                "ASCII serves as the foundation for character encoding in computing. Its standardized representation enables seamless data interchange between different systems\n"
                "In programming, it facilitates efficient conversion between characters and their binary representations\n"
                "contributing to the core of digital communication and data processing.\n"
                "\n In our programm you can convert (encode) plaintext into ASCII code just by selecting it from the main menu and entering the plaintext for encryption.\n"
                ;

char Binarydes[]= "Binary encoding is a fundamental concept in computing, where information is represented using a base-2 numeral system consisting of only 0s and 1s.\n"
"The concept of binary encoding dates back to ancient civilizations, but its systematic application in modern computing can be traced to the work of George Boole in the mid-19th century.\n"
"Claude Shannon later applied Boolean algebra to electronic circuits, paving the way for binary representation in digital systems.\n"
"Binary encoding forms the basis of digital computing and information storage. In a binary system, each bit (0 or 1) represents the most basic unit of information,\n"
"allowing for efficient data processing and storage.\n"
"In binary, each digit's place value is a power of 2. The rightmost bit is 2^0, the next is 2^1, and so on. \n"
"For example, the binary number 1011 represents (1 * 2^3) + (0 * 2^2) + (1 * 2^1) + (1 * 2^0) = 8 + 0 + 2 + 1 = 11 in decimal\n"
"Binary encoding serves as the foundation for many encryption algorithms. Techniques like XOR (exclusive OR) operations, bitwise shifting, and modular arithmetic on binary data form the core of cryptographic operations\n"
"Encryption algorithms use binary operations to transform plaintext into ciphertext, securing sensitive information.\n"
"\n You can easily transform and encrypt your plaintext into Binary data using ENDkrypter just by clicking and entering your plaintext in the Binary encoding option in the starting menu/\n"
;


char Base64des[] = "Base64 is another encoding method commonly used in computing to represent binary data using a set of 64 ASCII characters. Unlike binary encoding,\n"
"Base64 uses a larger set of characters, allowing it to represent binary data more efficiently in a human-readable format. \n"
"Base64 encoding originated from the need to transmit binary data over systems that were designed to handle only text data.\n "
"It has been a part of various internet protocols, including MIME (Multipurpose Internet Mail Extensions) for email attachments, \n"
"and is widely used in encoding data for data storage and transmission. It is used for encoding data such as images, audio files, and other binary formats, \n"
"making it suitable for data transmission over text-based protocols like email or HTML. Base64 encoding groups binary data \n into sets of 24 bits (3 bytes) and represents each group as four ASCII characters. "
"This is achieved by dividing the binary data into six-bit chunks, each corresponding to one of the 64 possible values in the Base64 character set.\n"
"While Base64 is not an encryption method per se, it is often used to encode binary data before transmission or storage. \n"
"It is not a secure encryption method but rather a method for representing binary data in a format that is safe for text-based systems.\n"
"\n You can Encode your plaintext input by selecting from the starting menu the Base64 Encryption option, enter your plaintext and get it encrypted as mentioned above.\n";


char Aesdes[] = "AES (Advanced Encryption Standard) is a symmetric encryption algorithm widely adopted for securing sensitive data. \n"
"It is used for encrypting and decrypting data in a way that is secure and efficient. \n"
"AES was established as the Advanced Encryption Standard by the U.S. National Institute of Standards and Technology (NIST) in 2001, succeeding the Data Encryption Standard (DES).\n"
"AES is a widely accepted and extensively used encryption standard.\n"
"AES is a symmetric key encryption algorithm, meaning the same key is used for both encryption and decryption. \n"
"It operates on fixed-size blocks of data (128 bits), making it suitable for a wide range of applications, from securing communications to encrypting files.\n"
"AES operates on blocks of data using a series of transformations, including substitution (SubBytes), permutation (ShiftRows), mixing (MixColumns), and key addition (AddRoundKey).\n"
"These operations are based on finite field mathematics, providing a high level of security.\n"
"Encryption Process:\n"
"1. Key Expansion: The original key is expanded into a set of round keys.\n"
"2. Initial Round: AddRoundKey operation using the initial round key.\n"
"3. Rounds: A specified number of rounds (10, 12, or 14, depending on key length) consisting of SubBytes, ShiftRows, MixColumns, and AddRoundKey operations.\n"
"4. Final Round: Similar to rounds but without the MixColumns operation\n"
"\n The AES encryption method is the most advanced one that ENDkrypter has by now.\n"
"\n Feell free to use it to encrypt your plaintext by slection from the main menu Advanced options => AES encryption +> enter plaintext.\n";

char Shades[]= "SHA-256 (Secure Hash Algorithm 256-bit) is a widely used cryptographic hash function that produces a fixed-size output (256 bits) regardless of the input size.\n"
"It is commonly employed for ensuring data integrity and creating digital signatures. \n"
"SHA-256 is part of the SHA-2 family of hash functions, designed by the National Security Agency (NSA) and published by the \n"
"National Institute of Standards and Technology (NIST) in 2001. SHA-256 is widely adopted for its security and efficiency\n"
"As a cryptographic hash function, SHA-256 takes an input (or message) of any size and produces a fixed-size output, \n"
"making it suitable for ensuring data integrity and creating unique identifiers for data.\n"
"SHA-256 uses a series of bitwise operations, modular additions, and logical functions based on the Merkle-Damgard construction. The core operations include \n"
"message padding, message block processing, and a set of logical functions. The strength of SHA-256 lies in its resistance to collisions\n"
"where two different inputs produce the same hash value.\n"
"\nHashing Process:\n"
"1. Message Padding: The input message is padded to a multiple of the block size\n"
"2. Initial Hash Values: A set of constant initial hash values is defined (8 hash values for SHA-256).\n"
"3. Message Block Processing: The padded message is processed in blocks, with each block influencing the hash value.\n"
"4. Final Hash Value: The final hash value is a fixed-size output representing the unique identifier for the input message.\n"
"\n Using ENDkrypter you can perform plaintext hashing with the method mentioned above and just by clickibg Advanced=> SHA-256 hashing => enter plaintext.\n";


switch (choice) {
    case 1:
        setLightGreenConsoleColor();
        system("cls");  // Clear  screen
        printf("\n\n\n\n\n");
        display_text_slowly_des(caesardes, 50);  
        while (getchar() != '\n');  // Wait for Enter key press
        system("cls");  //>>>>>
        break;
    case 2:
        system("cls");  // Clear  screen
        setLightGreenConsoleColor();
        printf("\n\n\n\n");
        display_text_slowly_des(vigeneredes, 30);  // >>>>>
        while (getchar() != '\n');  // >>>>>
        system("cls");  // >>>>>>
        break;
    case 3:
        system("cls");  //>>>>>>>>
	    setLightGreenConsoleColor();
        printf("\n\n\n\n");
        display_text_slowly_des(Asciides, 30);  //>>>>>
        while (getchar() != '\n');  
        system("cls");
        break;
    case 4:
        system("cls");  // >>>>>>
        setLightGreenConsoleColor();
        printf("\n\n\n\n");
        display_text_slowly_des(Binarydes, 30);  
        while (getchar() != '\n');  
        system("cls");  
        break;
    case 5:
        system("cls");  
        setLightGreenConsoleColor();
        printf("\n\n\n\n");
        display_text_slowly_des(Base64des, 30);  
        while (getchar() != '\n');  
        system("cls");  
        break;
    case 6:
        system("cls");  
        setLightGreenConsoleColor();
        printf("\n\n\n\n");
        display_text_slowly_des(Aesdes, 30);  
        while (getchar() != '\n');  
        system("cls");  
        break;
    case 7:
        system("cls"); 
        setLightGreenConsoleColor();
        printf("\n\n\n\n");
        display_text_slowly_des(Shades, 30);  
        while (getchar() != '\n');  
        system("cls"); 
        break;
    default:
        system("cls");  
        setLightGreenConsoleColor();
        printf("Not a valid choice");
        while (getchar() != '\n');  
        system("cls");  
        break;
}
} while (choice != 0);  // Exit if user choice is 0
}




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



// Function of SHA-256 hash the input data
void sha256Hash(const unsigned char *input, size_t length, unsigned char *hash) {
    SHA256_CTX sha256Context;  // Data structure for the SHA-256 algorithm
    SHA256_Init(&sha256Context);  // Initialize the SHA-256 algorithm
    // Update the SHA-256 context with the input data
    SHA256_Update(&sha256Context, input, length);
    // Finalize the SHA-256 hash computation and store the result in the 'hash' array
    SHA256_Final(hash, &sha256Context);
}




// Function for encrypting using the AES encryption algorithm 
void encryptAES(const unsigned char *plaintext, const unsigned char *key, unsigned char *ciphertext, int *ciphertext_len) {
    // Data structure for the cryptographic context (cipher context)
	EVP_CIPHER_CTX *ctx;       
    // Allocate memory for the cryptographic context
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        fprintf(stderr, "Error: Unable to create cipher context\n");
        exit(EXIT_FAILURE);
    }
    // Initialize the cryptographic context with AES-128 in ECB mode and the provided key
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_ecb(), NULL, key, NULL)) {
        fprintf(stderr, "Error: An error occurred during encryption initialization\n");
        exit(EXIT_FAILURE);
    }
    // Update the cryptographic context with the plaintext using AES encryption and obtain the ciphertext
    int len;
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, strlen((char *)plaintext))) {
        fprintf(stderr, "Error: An error occurred during encryption\n");
        exit(EXIT_FAILURE);
    }
    // Update the length of the resulting ciphertext
    *ciphertext_len = len;     
    // Finalize the encryption process, handle padding, and obtain the final ciphertext
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) {
        fprintf(stderr, "Error: An error occurred finalizing encryption\n");
        exit(EXIT_FAILURE);
    }
     // Update the length of the resulting ciphertext
    *ciphertext_len += len;  
    // Free the allocated memory for the cryptographic context
    EVP_CIPHER_CTX_free(ctx);
}




// Function for decrypting ciphertext using the AES decryption algorithm 
void decryptAES(const unsigned char *ciphertext, int ciphertext_len, const unsigned char *key, unsigned char *decryptedtext) {
    // Data structure for the cryptographic context (cipher context)
    EVP_CIPHER_CTX *ctx;      
    // Allocate memory for the cryptographic context
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        fprintf(stderr, "Error: Unable to create cipher context\n");
        exit(EXIT_FAILURE);
    }
    // Initialize the cryptographic context with AES-128 in ECB mode and the provided key for decryption
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_128_ecb(), NULL, key, NULL)) {
        fprintf(stderr, "Error: An error occurred starting decryption\n");
        exit(EXIT_FAILURE);
    }
    // Update the cryptographic context with the ciphertext, decrypting it, and obtain the decrypted text
    int len;
    if (1 != EVP_DecryptUpdate(ctx, decryptedtext, &len, ciphertext, ciphertext_len)) {
        fprintf(stderr, "Error: Error while decrypting\n");
        exit(EXIT_FAILURE);
    }
    // Update the length of the resulting decrypted text
    int decryptedtext_len = len;
    // Finalize the decryption process, handle padding, and obtain the final decrypted text
    if (1 != EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len)) {
        fprintf(stderr, "Error: Error finalizing decryption\n");
        exit(EXIT_FAILURE);
    }
      // Update the length of the resulting decrypted text
    decryptedtext_len += len; 
    // Free the allocated memory for the cryptographic context
    EVP_CIPHER_CTX_free(ctx);
    // Terminate the decrypted text with a null character for proper string termination
    decryptedtext[decryptedtext_len] = '\0';
}


// Function for Base64 encoding using the OpenSSL library
char* base64encode(const char* input, int length) {
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;
    b64 = BIO_new(BIO_f_base64());                   // Create a BIO filter for Base64 encoding/decoding
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);      // Set flag to disable newline characters
    bio = BIO_new(BIO_s_mem());   // Create a memory BIO for storing the Base64-encoded data
    BIO_push(b64, bio);          // Link the Base64 filter with the memory BIO
		// Write the input data to the BIO for encoding
    BIO_write(b64, input, length);
    BIO_flush(b64);
    BIO_get_mem_ptr(b64, &bufferPtr);  // Retrieve the pointer to the memory containing the encoded data
		char *encodedData = (char*)malloc(bufferPtr->length + 1);       // Allocate memory for the encoded data
    memcpy(encodedData, bufferPtr->data, bufferPtr->length);        // Copy the encoded data to the allocated buffer
		encodedData[bufferPtr->length] = '\0';  // Null-terminate the resulting string
    // Free the memory associated with the BIOs
    BIO_free_all(b64);
    
    return encodedData;
}


// Function for Base64 decoding using the OpenSSL library
char* base64decode(const char* input, int length) {
    BIO *bio, *b64;
    char *decodedData = (char*)malloc(length);
    // Create a BIO filter for Base64 encoding/decoding
    b64 = BIO_new(BIO_f_base64());
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL); // Set flag to disable newline characters
    // Create a memory BIO and link it with the Base64 filter
    bio = BIO_new_mem_buf(input, length);
    BIO_push(b64, bio);
    // Read the Base64-encoded data from the BIO and store it in the decodedData buffer
    int decodedLength = BIO_read(b64, decodedData, length);
    // Null-terminate the resulting string
    decodedData[decodedLength] = '\0';
    // Free the memory associated with the BIOs
    BIO_free_all(b64);
    
    return decodedData;
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

// Function to set the cursor position 
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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


// Function to set console text color to gray
void setGrayConsoleColor() {
    // Get the handle to the console
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Set the console text attribute to gray intensity
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
}


// Function to set console text color to bright magenta
void setBrightMagentaConsoleColor() {
//>>>>>>>
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // >>>>>>
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}


// >>>>>>
void setBrightRedConsoleColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
}



// >>>>>>>>
void setBrightGreenConsoleColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);//bright green 
}



// >>>>>>
void setCyanConsoleColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //cyan color
}


//>>>>>>>>>
void setLightBlueConsoleColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY); // light blue
}


//>>>>>>>>
void setPurpleConsoleColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);//purple
}


//>>>>>>>>>>>>>>>>>>>>>>> 
void setYellowConsoleColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);//yellow
}


//>>>>>>>>>>>>>>>>>>>>> 
void setRedConsoleColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED);//red
}

//>>>>>>>>>
void setBlueConsoleColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_BLUE); // Set color to blue
}


//>>>>>>>>>>
void setWhiteConsoleColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Set color to white
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>
void setLightGreenConsoleColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN);//>>>>light green
}



// Function to display loading dots for the "Loading" 
void loading() {
    int loading_dot, a;
    int d = 600;

    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tLoading"); 
    // Display loading dots animation
    for (loading_dot = 0; loading_dot < 6; loading_dot++) {
        a = loading_dot;
        printf(".");
        Sleep(d);
    }
    system("cls");
    printf("\n\n\n\t\t\t\t THANK YOU FOR WAITING!!!!!!");
    Sleep(1300); 
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

// Function to print a colored character to the console
void printColoredChar(char ch, int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);    
   
    SetConsoleTextAttribute(hConsole, color);
    putchar(ch);
    // Flush the output buffer
    fflush(stdout);
   
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
  
    usleep(10000);
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
    
    loading();     
    system("cls"); // Clear the  screen
    printf("\n");   
    
    display_description(); 
    system("cls");        
    printf("\n");         
    
		setWhiteConsoleColor(); 


 loadingdots();

system("cls"); 
printf("\n");  
setBlueConsoleColor(); 

	//Starting page
  printf("__________________________________________________________________________________________________________________________________________________\n");
  printf("_| Encryption |_________|  And  |_______________|  Decryption  |______________|  Programm  |______________________________________________________\n");
  printf("\n");
  printf("$###&&&&&&&&$$$$$$$ @#$&&^??!!@           &&$$&  @@#!$&&*#@!@                                                                                     \n");
  printf("$$##$&$$$$#$$&&$$$@ $$@#@ &$$#@           @###@  &$#@!    @@#$&                                                                                   \n");
  printf("&&&$#$(             ?!@@#  ^^$@(          &$##@  <<<<<      !!@#$                                                                                 \n");
  printf("##()@@@             $@*&&   &#@$?         #&$#@  >>>>>        ??!@#                                                                               \n");
  printf("$$&^&&@             &@!@$    @@#$*        &$$@!  ??#@!         @@#$@                                                                              \n");
  printf("$#@@&&&             &&^$#     &&##*       #@@#@  &&$#@            &&$#@                                                                           \n");
  printf("$$$###$&&&^^@@$#$&& ???@@      <>&@#      @#!##  !!@#!              **&$#                                                                         \n");
  printf("@@#^^//???&&^^$$$#< &&^$$       {$##@     ##@*@  **&$#               &&$#@ @@#   &&  $$     #@      &*  !@#@$^&  @@!#$^^&*#@  @!#$&&&  $$$        \n");
  printf("??@@##$             @#$$$        @@#@*    ?!#&2  ><><>              ^^$#@  **&  &&   ##@#    @#    &&   &$#   !@     &$#      &*       @!@#$$     \n");
  printf("$&&#@@#             &^#$@         &#@$$   #$&*@  !@#@!           &&^$#     ##@ &&    &&^ $#   @!  ##    &&$    ??    &&$      &#       !!@ &*     \n");
  printf("$///???             $$@#@          &&#$$  &&$@2  &&*$#          ??<@!      ##@$      @#@  &@   *&$#     $$$     &$   $$$      &@#!#^&  &*&  &$    \n");
  printf("&&$##@!             @@#$$           @$#@# #@$*$  #@#$@        **&$#        !@# &&    @@#   !&  @@!#     #@!@#@!*&^$  ###      &$       &#^   $$   \n");
  printf("$$$#$#>><???@@@@##& &@@#$            @$^&&#$@#&  @##!#      ##$!@          #$*  &&   *&&       ($#)     ?!@          @@@      &*       &??        \n");
  printf("&@@$$&&??&&&&@$$$$$ ##$&&            &&&&&&&&&&  ##$&&$$#@!@@#             &$$   &&  $$#       $#@!     @@!          $$@      &&@!@##  @@!        \n");
  printf("__________________________________________________________________________________________________________________________________________________\n");
  setYellowConsoleColor();
  printf("-Created By: | KOTSORGIOS PANAGIOTIS && SPYROPOYLOS DHMHTRHS |...\n");
  setRedConsoleColor();
  printf("=[ENDkrypter -version v1.1.1.0...]\n");
  setPurpleConsoleColor();
  printf("=[7 different encryption and decryption methods]\n");
  printf("=[1 for hashing]\n");
  printf("=[2 for .txt files]\n"); 
  setWhiteConsoleColor();
  printf("\n");
  printf("Press Enter to continue...");
   while (getchar() != '\n') {
//>>>>>>>>
            }
  system("cls");//>>>>>>>
  
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
            	int shift;
                setWhiteConsoleColor();
                printf("Enter the shift for Caesar encryption: ");
                setLightGreenConsoleColor(); 
                scanf("%d", &shift);
                setWhiteConsoleColor(); 
                caesarEncrypt(fileContent, shift);
                break;
            case 2:
            	char keyword[1000];
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
        	int shift;
            setWhiteConsoleColor(); 
            printf("Enter the shift for Caesar decryption: ");
            setLightGreenConsoleColor(); 
            scanf("%d", &shift);
            setWhiteConsoleColor();
            caesarDecrypt(fileContent, shift);
            break;
        case 2:
        	char keyword[1000];
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

    
    unsigned char sha256_hash[SHA256_DIGEST_LENGTH];

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
        char* encodedData = base64encode(input, strlen(input));

        printf("\nBase64 Encoded: ");
        setLightGreenConsoleColor();
        printf("%s \n", encodedData);
        setWhiteConsoleColor();

        // Free the allocated memory 
        free(encodedData);
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
    char* decodedData = base64decode(input, strlen(input));

    printf("\nBase64 Decoded: ");
    setLightGreenConsoleColor();
    printf("%s \n", decodedData);
    setWhiteConsoleColor();

    // Free the allocated memory 
    free(decodedData);
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
    encryptAES((unsigned char *)plaintext, aes_key, ciphertext, &ciphertext_len);

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
    decryptAES(ciphertext, ciphertext_len, aes_key, decryptedtext);

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
    sha256Hash((const unsigned char *)messagehash, strlen(messagehash), sha256_hash);
    printf("SHA-256 Hash: ");
    setLightGreenConsoleColor();
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        printf("%02x", sha256_hash[i]);
    }
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
system("cls"); 
printf("\n\n");

printf("Exited ENDkrypter session.\n");
setWhiteConsoleColor();
        
return 0;
}




