//
// Created by Kevin Leong on 11/15/20.
//

#include "Word.h"

Word::Word(string word) {
    this->word = word;
}
Word::Word(char *word) {
    this->word = word;
}
Word::Word(const Word &copy) {
    this->word = copy.word;
    this->titleList = copy.titleList;
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

DSHashTable<int, string> Word::getWordList(){
    return this->titleList;
}