#include "pch.h" // Если используете предкомпилированные заголовки
#include "TextProcessor.h"
#include <sstream>
#include <unordered_set>

std::string cleanText(const std::string& text) {
    std::string cleaned;
    bool inSpace = false;

    for (char c : text) {
        if (c == ' ' || c == '\t') {
            if (!inSpace) {
                cleaned += ' ';
                inSpace = true;
            }
        }
        else {
            cleaned += c;
            inSpace = false;
        }
    }

    // Trim leading and trailing spaces
    size_t start = cleaned.find_first_not_of(' ');
    size_t end = cleaned.find_last_not_of(' ');

    if (start == std::string::npos) {
        return ""; // String is all spaces
    }

    return cleaned.substr(start, end - start + 1);
}

Paragraph parseText(const std::string& text) {
    Paragraph paragraph;
    std::istringstream stream(text);
    std::string sentenceText;

    while (std::getline(stream, sentenceText, '.')) {
        Sentence sentence;
        std::string wordText;
        std::istringstream sentenceStream(cleanText(sentenceText));

        while (sentenceStream >> wordText) {
            sentence.addWord(Word(wordText));
        }

        if (!sentence.getWords().empty()) {
            paragraph.addSentence(sentence);
        }
    }

    return paragraph;
}

Word findUniqueWord(const Paragraph& paragraph) {
    if (paragraph.getSentences().empty()) {
        throw std::runtime_error("No sentences in the paragraph.");
    }

    const Sentence& firstSentence = paragraph.getSentences().front();
    std::unordered_set<std::string> otherWords;

    for (size_t i = 1; i < paragraph.getSentences().size(); ++i) {
        const Sentence& sentence = paragraph.getSentences()[i];
        for (const Word& word : sentence.getWords()) {
            otherWords.insert(word.value);
        }
    }

    for (const Word& word : firstSentence.getWords()) {
        if (otherWords.find(word.value) == otherWords.end()) {
            return word;
        }
    }

    throw std::runtime_error("No unique word found in the first sentence.");
}