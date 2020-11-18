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
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "DSHashTable.h"
#include "Author.h"

void runSearchEngine();
void buildIndex(DSHashTable<std::string, std::vector<std::string>> authorIndex);

#endif //SEARCH_ENGINE_RUNNER_H
