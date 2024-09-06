#ifndef ANIMATIONS_H
#define ANIMATIONS_H

void setGrayConsoleColor();
void setBrightMagentaConsoleColor();
void setBrightRedConsoleColor();
void setBrightGreenConsoleColor();
void setCyanConsoleColor();
void setLightBlueConsoleColor();
void setPurpleConsoleColor();
void setYellowConsoleColor();
void setRedConsoleColor();
void setBlueConsoleColor();
void setWhiteConsoleColor();
void setLightGreenConsoleColor();
void loading();
void display_text_slowly_des(const char *text, int delay);
void displayThankYou(const char *message, int delayBetweenChars, int loadingDotsDelay, int numLoadingDots);
void printColoredChar(char ch, int color);

#endif

