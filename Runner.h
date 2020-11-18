//
// Created by Sammy Timmins on 11/16/20.
//

#ifndef SEARCH_ENGINE_RUNNER_H
#define SEARCH_ENGINE_RUNNER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <dirent.h>
#include "rapidjson/document.h"
#include "DSHashTable.h"
#include "DSTree.h"
#include "Author.h"
#include "Word.h"

void runSearchEngine();
void buildIndexes(DSHashTable<Author, std::vector<std::string>> &authorIndex, DSTree<Word> &wordIndex);
std::string getFile(std::string &filePath);

#endif //SEARCH_ENGINE_RUNNER_H
