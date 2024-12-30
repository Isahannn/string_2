#ifndef SENTENCE_H
#define SENTENCE_H

#include <vector>
#include "Word.h"

class Sentence {
private:
    std::vector<Word> words;

public:
    void addWord(const Word& word) {
        words.push_back(word);
    }

    const std::vector<Word>& getWords() const {
        return words;
    }
};

#endif // SENTENCE_H