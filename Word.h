//
// Created by Kevin Leong on 11/15/20.
//

#include "DSHashTable.h"

using namespace std;

#ifndef SEARCH_ENGINE_WORD_H
#define SEARCH_ENGINE_WORD_H

#include <map>
#include <vector>

class Word {
private:
    string word;
    map<string, int> titleList;
    int totalFreq;
public:
    Word() = default;
    Word(string word);
    Word(char* word);
    Word(const Word &copy);

    bool operator> (const Word&)  const;
    bool operator< (const Word&)  const;
    bool operator== (const Word&) const;
    friend ostream& operator<<(ostream& os, const Word& word);

    string getWord();
    map<string, int>& getTitleList();
    void addPaperID(string paperID);

    int getTotalFreq();
    void iterTotalFreq();
};


#endif //SEARCH_ENGINE_WORD_H

