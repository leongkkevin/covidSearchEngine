//
// Created by Sammy Timmins on 11/19/20.
//

#include "IndexHandler.h"

std::vector<std::string> wordSearch(DSTree<Word>& wordIndex, std::string search)
{
    Word found, word(search);
    map<string, int> titlesMap;
    vector<string> titles;

    if(wordIndex.find(word))
    {
        found = wordIndex.get(word);
        titlesMap = found.getTitleList();

        map<string, int>::iterator it;

        for ( it = titlesMap.begin(); it != titlesMap.end(); it++ )
        {
             titles.push_back(it->first);
        }
    }
    else
    {
        cout << "No titles found for this word" << endl;
    }

    return titles;
}