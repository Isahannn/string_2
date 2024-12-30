#ifndef PARAGRAPH_H
#define PARAGRAPH_H

#include <vector>
#include "Sentence.h"

class Paragraph {
private:
    std::vector<Sentence> sentences;

public:
    void addSentence(const Sentence& sentence) {
        sentences.push_back(sentence);
    }

    const std::vector<Sentence>& getSentences() const {
        return sentences;
    }
};

#endif // PARAGRAPH_H