#ifndef WORD_H
#define WORD_H

#include <string>

class Word {
public:
    std::string value;

    Word(const std::string& v) : value(v) {}
};

#endif // WORD_H