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

### 1️⃣ Install Dependencies (if plan to contribute)

- 📦 **OpenSSL**: Install the full OpenSSL package.
- 🔨 **GCC-G++ Compiler**: Install **MINGW** to set up the compilation environment.


### 2️⃣ Execution

To run the compiled program, use the following command:


 EndKrypterV2.exe




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




| **Method**         | **Usage**                                          | **Advantages**                                      | **Complexity**                                              | **Decoding Difficulty**           |
|--------------------|----------------------------------------------------|----------------------------------------------------|-------------------------------------------------------------|-----------------------------------|
| 🅰️ **ASCII**        | Character-to-number encoding/decoding              | Simple to implement and fast                       | Basic conversion, no real encryption                         | 🟢 **Easy**: Direct reverse mapping |
| 🏛️ **Caesar Cipher**| Shifts characters by a fixed number of positions   | Easy to understand, good for basic encryption      | Vulnerable to frequency analysis attacks                     | 🟢 **Easy**: Can be brute-forced easily|
| 🔑 **Vigenere**     | Shifts characters based on a repeating keyword     | Stronger than Caesar due to varying shifts         | More secure than Caesar, but key repetition can be exploited  | 🟠 **Moderate**: Key length and frequency analysis |
| 💾 **Binary**       | Converts message into binary representation        | Universal encoding, compact for machine processing | Direct translation of data, simple encoding                  | 🟢 **Easy**: Reverse conversion from binary to text |
| 🔢 **Base64**       | Encodes binary data into ASCII string format       | Efficient for transmitting binary data             | Not real encryption, used mainly for encoding                | 🟢 **Easy**: Decoded using standard Base64 decoding |
| 🛡️ **AES**          | Symmetric key encryption, widely used              | Highly secure, fast decryption with the key        | Computationally efficient, secure against most attacks       | 🔴 **Hard**: Requires the key; virtually unbreakable without it |
| 🧩 **SHA-256**      | Cryptographic hashing, irreversible                | Ensures data integrity, secure one-way function    | Irreversible hash, secure but susceptible to brute force on short inputs | 🔴 **Impossible**: One-way function, cannot be decoded |


## 🛠️ **Technologies & Tools Used**

EndKrypter was created using the following programming languages, technologies, and tools:

| **Category** | **Icon** | **Description**                        |
|--------------|----------|----------------------------------------|
| **Languages** | ![C](https://skillicons.dev/icons?i=c) | C programming language                   |
| **Technologies** | ![OpenSSL](https://img.icons8.com/color/48/000000/lock--v1.png) | OpenSSL for cryptographic operations     |
| **Compilers** | ![GCC](https://img.icons8.com/ios/50/000000/gcc.png) | GCC for compiling (alternative icon)     |
| **Editors** | ![VSCode](https://skillicons.dev/icons?i=vscode) | Visual Studio Code for development        |
| **Operating System** | ![Windows](https://skillicons.dev/icons?i=windows) | Windows as the operating environment      |
| **Build Tools** | ![Make](https://skillicons.dev/icons?i=make) | Make for build automation                 |
| **Version Control** | ![Git](https://skillicons.dev/icons?i=git) | Git for version control                   |



