#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <windows.h>

extern void waitForEnter();
extern void SetConsoleColor(WORD color);
extern void Open_Website(std::string Link);
extern void ask(std::string question, std::string &retur);
extern void intask(const std::string& question, int& retur);
extern void ucharask(const std::string& question, unsigned char& retur);
#endif // HEADER_H
