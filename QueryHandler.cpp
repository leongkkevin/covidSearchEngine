//
// Created by Sammy Timmins on 11/22/20.
//

#include "QueryHandler.h"

using namespace std;

void query(DSTree<Word> wordIndex, DSHashTable<string, Title> authorIndex, DSTree<string>& searchResults, int numArticles)
{
    bool queryRun = true;
    cout << "Welcome to the COVID-19 Research Database Search Engine" << endl;
    while(queryRun)
    {
        string selectionString;
        int selection;
        cout << "Please select one of the following options:\n" //gui selection interface
             << "1. Boolean Query\n"
             << "2. Get total number of articles indexed\n"
             << "3. Get average number of words per indexed article\n"
             << "4. Get the total number of words in all indexed articles\n"
             << "5. Total number of unique authors\n"
             << "6. 50 most frequent words in indexed articles\n"
             << "7. Clear index\n"
             << "8. Parse corpus and populate index OR open a persistence file\n"
             << "0. Exit\n"
             << "Selection: ";

        while(true) //handles incorrect inputs
        {
            try
            {
                getline(cin, selectionString);
                selection = stoi(selectionString);
                break;
            }
            catch(invalid_argument)
            {
                cin.clear();
                cout << "\nInvalid selection please try again.\nSelect a number 0 - 8: ";
            }
        }

        if(selection < 0 || selection > 8) //makes sure input is in the correct range
        {
            cin.clear();
            cout << "\nInvalid selection please try again.\nSelect a number 0 - 8: ";

            while(selection < 0 || selection > 8)
            {
                try
                {
                    getline(cin, selectionString);
                    selection = stoi(selectionString);
                    break;
                }
                catch(invalid_argument)
                {
                    cin.clear();
                    cout << "\nInvalid selection please try again.\nSelect a number 0 - 8: ";
                }
            }
        }

        switch(selection) //calls correct function based on input
        {
            case 1:
            {
                string searchQuery, query; //gets boolean search query input
                cout << "Please enter your boolean search query. Options are AND, OR, AUTHOR, NOT, and a single word" << endl;
                while(getline(cin, searchQuery, ' ')) //loops through the entire input
                {
                    toLower(searchQuery);
                    if(searchQuery == "and") //if its an AND request
                    {
                        getline(cin, query, ' '); //gets the next word
                        while(query != "not" || query != "author") //loops in and until another boolean request is received
                        {
                            DSTree<string> foundTitles;
                            wordSearch(wordIndex, query, foundTitles);
                            if(!(searchResults.getNumNodes() == 0)) //if the search results already has results in it
                            {
                                /**
                                 * compare two avl trees remove items not in both
                                 */
                            }
                            else
                            {
                                searchResults = foundTitles;
                            }
                            getline(cin, query, ' ');
                            toLower(query);
                        }
                        if(query == "not")
                        {
                            DSTree<string> foundTitles;
                            getline(cin, query, ' ');
                            wordSearch(wordIndex, query, foundTitles);
                            /**
                             * remove all nodes in foundTitles from searchResults tree
                             */
                        }
                        else if(query == "author")
                        {
                            DSTree<string> foundTitles;
                            getline(cin, query, ' ');
                            authorSearch(authorIndex, query, foundTitles);
                            /**
                             * compare two avl trees remove items not in both
                             */
                        }
                    }
                    else if(searchQuery == "or") //if OR query
                    {
                        while(query != "not" || query != "author") //loops until a NOT or AUTHOR query
                        {
                            getline(cin, query, ' ');
                            wordSearch(wordIndex, query, searchResults);
                            getline(cin, query, ' ');
                            toLower(query);
                        }
                        if(query == "not")
                        {
                            DSTree<string> foundTitles;
                            getline(cin, query, ' ');
                            wordSearch(wordIndex, query, foundTitles);
                            /**
                             * remove all nodes in foundTitles from searchResults tree
                             */
                        }
                        else if(query == "author")
                        {
                            DSTree<string> foundTitles;
                            getline(cin, query, ' ');
                            authorSearch(authorIndex, query, foundTitles);
                            /**
                             * compare two avl trees remove items not in both
                             */
                        }
                    }
                    else if(searchQuery == "author")
                    {
                        DSTree<string> foundTitles;
                        getline(cin, query, ' ');
                        authorSearch(authorIndex, query, foundTitles);

                        if(!(searchResults.getNumNodes() == 0))
                        {
                            /**
                             * compare two avl trees remove items not in both
                             */
                        }
                        else
                        {
                            searchResults = foundTitles;
                        }
                    }
                    else
                    {
                        DSTree<string> foundTitles;
                        wordSearch(wordIndex, query, searchResults);
                    }
                }
                break;
            }

            case 2:
            {
                cout << "There are " << numArticles << " articles indexed." << endl;
                break;
            }

            case 3:
            {
                /**
                 * get average words per articles
                 */
                break;
            }

            case 4:
            {
                cout << "There are a total of " << wordIndex.getNumNodes() << " unique words in the index." << endl;
                break;
            }

            case 5:
            {
                cout << "There are a total of " << authorIndex.getCount() << " unique authors in the index." << endl;
                break;
            }

            case 6:
            {
                /**
                 * return 50 most common words
                 */
                break;
            }

            case 7:
            {
                /**
                 * empty indexes
                 */
                break;
            }

            case 8:
            {
                /**
                 * do whatever parse corpus and populate index means
                 */
                break;
            }

            case 0:
            {
                cout << "Thank you for using our COVID-19 database search engine!" << endl;
                queryRun = false;
                break;
            }
        }
    }
}