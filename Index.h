//
// Created by Sammy Timmins on 11/19/20.
//

#ifndef SEARCH_ENGINE_INDEX_H
#define SEARCH_ENGINE_INDEX_H

#include <string>
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <sstream>
#include <set>

#include "porter2_stemmer.h"
#include "rapidjson/document.h"
#include "Word.h"
#include "Title.h"
#include "DSTree.h"
#include "DSHashTable.h"

void buildIndexes(DSHashTable<std::string, Title> &authorIndex, DSTree<Word> &wordIndex, std::string &path);
void makeFillerSet(set<string> &fillerSet);
std::string getFile(std::string &filePath);

#endif //SEARCH_ENGINE_INDEX_H
