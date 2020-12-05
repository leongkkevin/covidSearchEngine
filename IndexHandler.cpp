//
// Created by Sammy Timmins on 11/19/20.
//

#include "IndexHandler.h"

void wordSearch(DSTree<Word>& wordIndex, string& search, map<string, int>& foundTitles)
{
    Porter2Stemmer::stem(search);
    toLower(search);
    Word found, word(search);

    if(wordIndex.getNumNodes() > 0)
    {
        if(wordIndex.find(word))
        {
            found = wordIndex.get(word);

            map<string, int>::iterator it;
            int x = 0;
            for ( it = found.getTitleList().begin(); it != found.getTitleList().end(); it++)
            {
                //change this to insert into avl tree after demo
                foundTitles.insert (std::pair<string,int>(it->first,it->second));
                //cout << it->first << endl;
                x++;
            }
            //cout << x << " files" << endl;
        }
    }
    else
    {
        cout << "No index opened, please open an index to search." << endl;
    }

}

void authorSearch(DSHashTable<string, Title>& authorIndex, string& search, map<string, int>& foundTitles)
{
    toLower(search);
    Title found;

    if(authorIndex.find(search))
    {
        found = authorIndex.get(search);
        for(int i = 0; i < found.getTitles().size(); i++)
        {
            //foundTitles.insert(found.getTitleAt(i));
            foundTitles.insert(std::pair<string,int>(found.getTitles().at(i), i));
        }
    }
}