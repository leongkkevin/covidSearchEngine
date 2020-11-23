//
// Created by Sammy Timmins on 11/22/20.
//

#ifndef SEARCH_ENGINE_QUERYHANDLER_H
#define SEARCH_ENGINE_QUERYHANDLER_H

#include <string>
#include <iostream>
#include <sstream>

#include "DSTree.h"
#include "DSHashTable.h"
#include "Word.h"
#include "Title.h"
#include "IndexHandler.h"

void query(DSTree<Word> wordIndex, DSHashTable<string, Title> authorIndex, DSTree<std::string>& searchResults, int numArticles);

#endif //SEARCH_ENGINE_QUERYHANDLER_H
