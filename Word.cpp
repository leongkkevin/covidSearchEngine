//
// Created by Kevin Leong on 11/15/20.
//

#include "Word.h"

string Word::getWord(){
    return this->word;
}

DSHashTable<int, string> Word::getWordList(){
    return this->titleList;
}

