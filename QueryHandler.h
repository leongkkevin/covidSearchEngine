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

void query(DSTree<Word> wordIndex, DSHashTable<string, Title> authorIndex, map<string, int>& searchResults);
int checkInput(int &input, int low, int high);

void printSearchResults(map<string, int> &map);
void sortSearchResults(map<string, int> &searchResults, map<int, string> &sortedSearchResults);

#endif //SEARCH_ENGINE_QUERYHANDLER_H
