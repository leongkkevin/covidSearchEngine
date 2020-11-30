//
// Created by Sammy Timmins on 11/22/20.
//

//The thingy: /Users/kevinleong/Documents/cs2341_data/
//The thingy but practice: /Users/kevinleong/Documents/ds_03/

#include "QueryHandler.h"

using namespace std;

void query(DSTree<Word> wordIndex, DSHashTable<string, Title> authorIndex, map<string,int> & searchResults)
{
    bool queryRun = true;
    int numArticles = 0;
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
                cout << "Invalid selection please try again.\nSelect a number 0 - 8: ";
            }
        }

        checkInput(selection, 0, 8);

        switch(selection) //calls correct function based on input
        {
            case 1:
            {
                string searchQuery, query; //gets boolean search query input
                stringstream ss;
                cout << "Please enter your boolean search query. Options are AND, OR, AUTHOR, NOT, and a single word" << endl;
                getline(cin, searchQuery);
                toLower(searchQuery);

                searchQuery += " /0";

                ss << searchQuery;
                while(getline(ss, searchQuery, ' ')) //loops through the entire input
                {
                    /** AND */
                    if(searchQuery == "and") //if its an AND request
                    {
                        getline(ss, query, ' '); //gets the next word
                        while(query != "not" && query != "author") //loops in and until another boolean request is received
                        {
                            if(query == "/0"){
                                break;
                            }

                            map<string, int> foundTitles;
                            wordSearch(wordIndex, query, foundTitles);
                            if(!searchResults.empty()) //if the search results already has results in it
                            {
                                /**
                                 * compare two maps and remove items not in both
                                 */
                                map<string, int> tempMap;
                                auto it = searchResults.begin();

                                while(it != searchResults.end()){
                                    if(foundTitles.count(it->first) != 0)
                                    {
                                        //searchResults.erase(it);
                                        tempMap.insert(pair<string, int>(it->first, it->second));
                                    }
                                    it++;
                                }
                                searchResults.clear();
                                searchResults = tempMap;
                            }
                            else
                            {
                                searchResults = foundTitles;
                            }
                            getline(ss, query, ' ');
                            toLower(query);
                        }
                        if(query == "not")
                        {
                            map<string, int> foundTitles;
                            getline(ss, query, ' ');
                            wordSearch(wordIndex, query, foundTitles);
                            /**
                             * remove all elements in foundTitles from searchResults map
                             */

                            map<string, int> tempMap;
                            auto it = searchResults.begin();

                            while(it != searchResults.end()){
                                if(foundTitles.count(it->first) == 0){
                                    tempMap.insert(pair<string, int>(it->first, it->second));
                                    //searchResults.erase(it);
                                }
                                it++;
                            }
                            searchResults.clear();
                            searchResults = tempMap;

                        }
                        else if(query == "author")
                        {
                            map<string, int> foundTitles;
                            getline(ss, query, ' ');
                            authorSearch(authorIndex, query, foundTitles);
                            /**
                             * compare two MAPS remove items not in both
                             */
                            map<string, int> tempMap;

                            auto it = searchResults.begin();

                            while(it != searchResults.end()){
                                if(foundTitles.count(it->first) != 0){
                                    tempMap.insert(pair<string, int>(it->first, it->second));
                                    //searchResults.erase(it);
                                }
                                it++;
                            }
                            searchResults.clear();
                            searchResults = tempMap;
                        }
                        break;
                    }

                    /** OR */
                    else if(searchQuery == "or") //if OR query
                    {
                        getline(ss, query, ' ');

                        while(query != "not" && query != "author") //loops until a NOT or AUTHOR query
                        {
                            if(query == "/0"){
                                break;
                            }

                            /** Inserts it all into searchResults */
                            toLower(query);
                            wordSearch(wordIndex, query, searchResults);

                            getline(ss, query, ' ');
                            toLower(query);
                        }
                        if(query == "not")
                        {
                            map<string, int> foundTitles;
                            getline(ss, query, ' ');
                            wordSearch(wordIndex, query, foundTitles);
                            /**
                             * remove all elements in foundTitles from searchResults map
                             */

                            map<string, int> tempMap;
                            auto it = searchResults.begin();

                            while(it != searchResults.end()){
                                if(foundTitles.count(it->first) == 0){
                                    tempMap.insert(pair<string, int>(it->first, it->second));
                                    //searchResults.erase(it);
                                }
                                it++;
                            }
                            searchResults.clear();
                            searchResults = tempMap;
                        }
                        else if(query == "author")
                        {
                            map<string, int> foundTitles;
                            getline(ss, query, ' ');
                            authorSearch(authorIndex, query, foundTitles);
                            /**
                             * compare two MAPPY MAPS and remove items not in both
                             */

                            map<string, int> tempMap;
                            auto it = searchResults.begin();

                            while(it != searchResults.end()){
                                if(foundTitles.count(it->first) != 0){
                                    //searchResults.erase(it);
                                    tempMap.insert(pair<string, int>(it->first, it->second));
                                }
                                it++;
                            }
                            searchResults.clear();
                            searchResults = tempMap;
                        }
                        break;
                    }

                    /** AUTHOR */
                    else if(searchQuery == "author")
                    {
                        map<string, int> foundTitles;
                        getline(ss, query, ' ');
                        authorSearch(authorIndex, query, foundTitles);

                        if(!searchResults.empty())
                        {
                            /**
                             * compare two MAPS remove items not in both
                             */

                            map<string, int> tempMap;
                            auto it = searchResults.begin();

                            while(it != searchResults.end()){
                                if(foundTitles.count(it->first) != 0){
                                    //searchResults.erase(it);
                                    tempMap.insert(pair<string, int>(it->first, it->second));
                                }
                                it++;
                            }
                            searchResults.clear();
                            searchResults = tempMap;

                        }
                        else
                        {
                            searchResults = foundTitles;
                        }
                        break;
                    }
                    else
                    {
                        //DSTree<string> foundTitles;
                        wordSearch(wordIndex, searchQuery, searchResults);
                        break;
                    }
                }

                map<int,string> sortedSearchResults;
                sortSearchResults(searchResults, sortedSearchResults);

                /** prints search results */
                printSearchResults(searchResults);
                searchResults.clear();
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
                authorIndex.clear();
                break;
            }

            case 8:
            {
                int eightSelection = 0;
                cout << "Would you like to parse a directory or open a persistence file?\n"
                     << "1. Parse\n2. Persistence File\n"
                     << "Selection: ";

                while(true) //handles incorrect inputs
                {
                    try
                    {
                        getline(cin, selectionString);
                        eightSelection = stoi(selectionString);
                        break;
                    }
                    catch(invalid_argument)
                    {
                        cin.clear();
                        cout << "Invalid selection please try again.\nSelect a number 1 - 2: ";
                    }
                }

                checkInput(eightSelection, 1, 2);

                switch(eightSelection)
                {
                    case 1:
                    {
                        string path;
                        cout << "Please give the absolute path to the directory you would like to parse:" << endl;
                        getline(cin, path);
                        cout << "Building your index..." << endl;
                        numArticles = buildIndexes(authorIndex, wordIndex, path);
                        break;
                    }
                    case 2:
                    {
                        /**
                         * uh
                         * persistence file?
                         * ¯\_(ツ)_/¯
                         */
                        break;
                    }
                }
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

void sortSearchResults(map<string, int> &searchResults, map<int,string> &sortedSearchResults){
    auto it = searchResults.begin();

    while(it != searchResults.end()){
        sortedSearchResults.insert(pair<int, string>(it->second, it->first));
        it++;
    }
}

void printSearchResults(map<string, int> &searchResults) {
    auto it = searchResults.begin();

    while(it != searchResults.end()){
        cout << it->first << endl;
        it++;
    }

    cout << "Found " << searchResults.size() << " files!" << endl;
}

int checkInput(int &input, int low, int high)
{
    if(input < low || input > high) //makes sure input is in the correct range
    {
        cin.clear();
        cout << "Invalid selection please try again.\nSelect a number " << low
             << " - " << high << ": ";

        string selectionString;
        while(true)
        {
            try
            {
                getline(cin, selectionString);
                input = stoi(selectionString);
                break;
            }
            catch(invalid_argument)
            {
                cin.clear();
                cout << "Invalid selection please try again.\nSelect a number " << low
                     << " - " << high << " : ";
            }
        }
        checkInput(input, low, high);
    }
    else if(input >= low && input <= high)
    {
        return input;
    }
}