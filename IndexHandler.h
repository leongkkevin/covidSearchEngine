//
// Created by Sammy Timmins on 11/19/20.
//

#ifndef SEARCH_ENGINE_INDEXHANDLER_H
#define SEARCH_ENGINE_INDEXHANDLER_H

#include <vector>
#include <string>
#include <map>
#include "DSTree.h"
#include "Word.h"

std::vector<std::string> wordSearch(DSTree<Word>& wordIndex, std::string search);

#endif //SEARCH_ENGINE_INDEXHANDLER_H
