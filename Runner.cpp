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
    string path = "/Users/stimmins/Documents/cs2341_data";
    buildIndexes(authorIndex, wordIndex, path);
}

void runSearchEngine(string &wordToFind, string &directoryPath)
{
    DSHashTable<string, Title> authorIndex;
    DSTree<Word> wordIndex;
    vector<string> foundTitles;

    buildIndexes(authorIndex, wordIndex, directoryPath);
    foundTitles = wordSearch(wordIndex, wordToFind);

    for(int i = 0; i < foundTitles.size(); i++)
    {
        string pathForTitle = directoryPath + "/" + foundTitles[i] + ".json";
        rapidjson::Document doc;
        doc.Parse(getFile(pathForTitle).c_str());

        cout << doc["metadata"]["title"].GetString() << endl;
    }
}