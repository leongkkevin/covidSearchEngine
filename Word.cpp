//
// Created by Kevin Leong on 11/15/20.
//

#include "Word.h"

Word::Word(string word) {
    this->word = word;
    this->totalFreq = 0;
}
Word::Word(char *word) {
    this->word = word;
    this->totalFreq = 0;
}
Word::Word(const Word &copy) {
    this->word = copy.word;
    this->titleList = copy.titleList;
    this->totalFreq = copy.totalFreq;
}

bool Word::operator>(const Word &comp) const {
    return this->word > comp.word;
}
bool Word::operator<(const Word &comp) const {
    return this->word < comp.word;
}
bool Word::operator==(const Word &comp) const {
    return this->word == comp.word;
}

string Word::getWord(){
    return this->word;
}
map<string, int>& Word::getTitleList() {
    return this->titleList;
}

void Word::addPaperID(string paperID) {
    this->titleList[paperID];
    this->titleList.at(paperID) = 0;
}

int Word::getTotalFreq() {
    return this->totalFreq;
}

void Word::iterTotalFreq() {
    this->totalFreq++;
}


