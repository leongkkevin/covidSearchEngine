//
// Created by Sammy Timmins on 11/16/20.
//

#ifndef SEARCH_ENGINE_RUNNER_H
#define SEARCH_ENGINE_RUNNER_H

#include <string>
#include <iostream>
#include <fstream>
#include <dirent.h>
#include "rapidjson/document.h"
#include "DSHashTable.h"
#include "DSTree.h"
#include "Word.h"
#include "Title.h"

void runSearchEngine();
void buildIndexes(DSHashTable<std::string, Title> &authorIndex, DSTree<Word> &wordIndex);
std::string getFile(std::string &filePath);

#endif //SEARCH_ENGINE_RUNNER_H
