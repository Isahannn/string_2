#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include <string>
#include "Paragraph.h"

// Объявления функций
std::string cleanText(const std::string& text);
Paragraph parseText(const std::string& text);
Word findUniqueWord(const Paragraph& paragraph);

#endif // TEXTPROCESSOR_H