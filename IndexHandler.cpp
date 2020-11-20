//
// Created by Sammy Timmins on 11/19/20.
//

#include "IndexHandler.h"

void wordSearch(DSTree<Word>& wordIndex, std::string& search, std::vector<std::string>& foundTitles)
{
    Porter2Stemmer::stem(search);
    Word found, word(search);
    map<string, int> titlesMap;

    found = wordIndex.get(word);

    if(wordIndex.find(word))
    {
        found = wordIndex.get(word);
        titlesMap = found.getTitleList();

        map<string, int>::iterator it;

        for ( it = titlesMap.begin(); it != titlesMap.end(); it++ )
        {
             //foundTitles.push_back(it->first);
             cout << it->first << endl;
        }
    }
    else
    {
        cout << "No titles found for this word" << endl;
    }
}