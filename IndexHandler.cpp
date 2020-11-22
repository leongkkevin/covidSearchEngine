//
// Created by Sammy Timmins on 11/19/20.
//

#include "IndexHandler.h"

void wordSearch(DSTree<Word>& wordIndex, std::string& search, std::vector<std::string>& foundTitles)
{
    Porter2Stemmer::stem(search);
    toLower(search);
    Word found, word(search);

    if(wordIndex.find(word))
    {
        found = wordIndex.get(word);

        map<string, int>::iterator it;
        int x = 0;
        for ( it = found.getTitleList().begin(); it != found.getTitleList().end(); it++)
        {
             //foundTitles.push_back(it->first);
             cout << it->first << endl;
             x++;
        }
        cout << x << " files" << endl;
    }
    else
    {
        cout << "No titles found for this word" << endl;
    }
}