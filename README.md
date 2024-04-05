# EndKrypter
EndKrypter is a simple Encryption and Decryption tool written fully in C for Windows platforms.

The program i created, named ENDkrypter, implements a variety of encoding and decoding methods aimed at protecting personal messages. Its functionality is based on various encoding methods, such as ASCII, Caesar, Vigenere, binary, base64, AES, and SHA-256, giving the user the option to choose.

The ASCII encoding method corresponds each character to an ASCII number and replaces each character with its corresponding ASCII number. Decoding restores the ASCII numbers to their original characters.

The Caesar method applies a key, i.e., a fixed shift, to replace each character with another character located at a specific distance in the ASCII table. Decoding returns the original message by reversing the shift.

The Vigenere encoding method uses a keyword to apply multiple shifts to each character of the message. Decoding restores the original message using the same keyword.

The binary and base64 methods convert the message to binary or base64 format, respectively. Decoding retrieves the original message from binary or base64 format.

The AES and SHA-256 methods are used for advanced encryption. AES (Advanced Encryption Standard) uses a key for encoding and decoding data, while the SHA-256 method is used to compute the hash of the message.

Additionally, the program has the ability to encrypt and decrypt text files through two different methods for wider use.

Such a computer application can be useful in various environments and scenarios for various reasons, such as:

    Communication Security: Message encryption is crucial for maintaining the confidentiality of data during communication. It can be used, for example, in securely exchanging sensitive information.
    File Protection: When storing data in files, encryption can protect the files from unauthorized access. It can be used to protect personal or professional files.
    Experimental Learning: The program can be used as an educational tool for understanding basic encryption algorithms and encoding processes.

In general, the program provides a versatile tool for secure and flexible use of encryption and decoding in various fields and environments.

For compilation and execution:

    Install the OpenSSL library (full package).
    Install a GCC-G++ compiler (MINGW) to create the compilation environment.
    Open a command prompt and navigate to the directory where the <FILENAME>.c file is stored.
    Enter the command: gcc -o <filename\to\be\saved\as>.exe <filename>.c -I"\path\to\Openssl\include" -L"\path\to\openssl\lib" -lssl -lcrypto
    For example:
    gcc -o ENDKRYPTER.exe ENDKRYPTER.c -I"C:\Program Files\OpenSSL-Win64\include" -L"C:\Program Files\OpenSSL-Win64\lib\VC\x64\MTd" -lssl -lcrypto
    And for execution:
    <FILENAME>.exe
    I do not use –trigraphs as the program is designed for the Windows environment and not for Linux, as I would have unwanted actions.


