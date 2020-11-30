//
// Created by Sammy Timmins on 11/16/20.
//

#include "Runner.h"

using namespace std;

/**
 * main function to run the search engine
 */

void runSearchEngine()
{
    DSHashTable<string, Title> authorIndex;
    DSTree<Word> wordIndex;
    DSTree<string> searchResults;
    query(wordIndex, authorIndex, searchResults);
}

void runSearchEngine(string &wordToFind, string &directoryPath)
{
    DSHashTable<string, Title> authorIndex;
    DSTree<Word> wordIndex;
    DSTree<string> foundTitles;

    buildIndexes(authorIndex, wordIndex, directoryPath);
    wordSearch(wordIndex, wordToFind, foundTitles);
}