#ifndef UTILS_H
#define UTILS_H

void display_text_slowly_des(const char *text, int delay);
void displayThankYou(const char *message, int delayBetweenChars, int loadingDotsDelay, int numLoadingDots);
void smallbox();
void gotoxy(int x, int y);

void display_description();
void box();
void custom_clear_screen();
void loading();
void printColoredChar(char ch, int color);
void loadingdots();

#endif

