//
// Created by Kevin Leong on 11/15/20.
//

#include "DSHashTable.h"

using namespace std;

#ifndef SEARCH_ENGINE_WORD_H
#define SEARCH_ENGINE_WORD_H


class Word {
private:
    string word;
    DSHashTable<int, string> titleList;
public:
    Word() = default;
    Word(string word);
    Word(char* word);
    Word(const Word &copy);

    bool operator> (const Word&)  const;
    bool operator< (const Word&)  const;
    bool operator== (const Word&) const;

    string getWord();
    DSHashTable<int, string> getWordList();
};


#endif //SEARCH_ENGINE_WORD_H

