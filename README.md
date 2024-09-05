# 🔐 **EndKrypter**

**EndKrypter** is a simple **Encryption** and **Decryption** tool written entirely in C for **Windows** platforms.

## ⚙️ **Overview**

EndKrypter provides a variety of encoding and decoding methods aimed at protecting personal messages. This program offers several encoding techniques, including:

- 🅰️ **ASCII**
- 🏛️ **Caesar Cipher**
- 🔑 **Vigenere Cipher**
- 💾 **Binary**
- 🔢 **Base64**
- 🛡️ **AES**
- 🧩 **SHA-256**

Each method allows users to encrypt or decrypt messages in different ways, making EndKrypter a versatile tool for multiple use cases.


## 🔍 **Encryption Methods & Descriptions**

| Method                | Description                                                                                  | Example Usage                    |
|-----------------------|----------------------------------------------------------------------------------------------|-----------------------------------|
| 🅰️ **ASCII**           | Encodes each character to its corresponding ASCII number and replaces it in the message.     | `A -> 65`                        |
| 🏛️ **Caesar Cipher**   | Shifts each character in the message by a fixed number of positions.                         | `ABC -> DEF` (shift of 3)         |
| 🔑 **Vigenere**        | Uses a keyword to apply multiple shifts to each character in the message.                    | Keyword: `KEY`                   |
| 💾 **Binary**          | Converts the message to a binary format.                                                     | `A -> 01000001`                  |
| 🔢 **Base64**          | Encodes the message in Base64, commonly used in data transmission.                           | `A -> QQ==`                      |
| 🛡️ **AES**             | Utilizes the **Advanced Encryption Standard** with a key for secure encryption.              | 256-bit encryption               |
| 🧩 **SHA-256**         | Computes a cryptographic hash of the message (one-way function).                             | Produces a 64-character hash      |

## 🛠️ **Additional Features**

- **File Encryption & Decryption**: EndKrypter also supports the encryption and decryption of text files via two different methods.

## 📂 **Practical Use Cases**

| Use Case                | Description                                                                                 |
|-------------------------|---------------------------------------------------------------------------------------------|
| 🔐 **Communication Security** | Encrypt messages for secure transmission, such as sensitive information exchange.         |
| 🗄️ **File Protection**      | Encrypt personal or professional files to prevent unauthorized access.                    |
| 📚 **Educational Tool**      | Learn about basic encryption algorithms and encoding processes for educational purposes.  |





## 🛠️ **Setup Instructions**

Follow the steps below to compile and run **EndKrypter** on your Windows system:

### 1️⃣ Install Dependencies

- 📦 **OpenSSL**: Install the full OpenSSL package.
- 🔨 **GCC-G++ Compiler**: Install **MINGW** to set up the compilation environment.

### 2️⃣ Compilation

Open a command prompt and navigate to the directory where the `ENDKRYPTER.c` file is stored.

Run the following command:


gcc -o <filename\to\be\saved\as>.exe <filename>.c -I"\path\to\Openssl\include" -L"\path\to\openssl\lib" -lssl -lcrypto

🔧 Example:

bash

gcc -o ENDKRYPTER.exe ENDKRYPTER.c -I"C:\Program Files\OpenSSL-Win64\include" -L"C:\Program Files\OpenSSL-Win64\lib\VC\x64\MTd" -lssl -lcrypto

3️⃣ Execution

To run the program, use:

bash

<FILENAME>.exe

css


This markdown preserves the emoji-based steps and proper code formatting, making the instructi



## 🎯 **Why Use EndKrypter?**

EndKrypter is ideal for several purposes:

- 🔐 **Secure Communication**: Protect confidential messages.
- 🗂️ **File Safety**: Keep sensitive files away from prying eyes.
- 📚 **Learning Platform**: Explore encryption techniques and algorithms interactively.

## ⚠️ **Note**

- ❌ The program is built for the **Windows** environment.
- ❌ It does not use `–trigraphs` as these are Linux-specific and may lead to unintended behavior in Windows.

## 💻 **License**

**EndKrypter** is open-source software. Feel free to modify and distribute it under the **MIT License**.

## 🌟 **Contributing**

Feel free to open issues and submit pull requests for new features, bug fixes, or improvements.





