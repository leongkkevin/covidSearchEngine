//
// Created by Sammy Timmins on 11/19/20.
//

#include "IndexHandler.h"

void wordSearch(DSTree<Word>& wordIndex, string& search, DSTree<string>& foundTitles)
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
             //change this to insert into avl tree after demo
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

void authorSearch(DSHashTable<string, Title>& authorIndex, string& search, DSTree<string>& foundTitles)
{
    toLower(search);
    Title found;

    if(authorIndex.find(search))
    {
        found = authorIndex.get(search);
        for(int i = 0; i < found.getTitles().size(); i++)
        {
            foundTitles.insert(found.getTitleAt(i));
        }
    }
    else
    {
        cout << "No titles found for this author" << endl;
    }
}