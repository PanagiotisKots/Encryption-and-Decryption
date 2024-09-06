#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

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

