#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

#include "Help.h"
#include "Animations.h"



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

