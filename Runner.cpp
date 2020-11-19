//
// Created by Sammy Timmins on 11/16/20.
//

#include "Runner.h"

using namespace std;
using namespace rapidjson;

/**
 * main function to run the search engine
 */

void runSearchEngine()
{
    DSHashTable<string, Title> authorIndex;
    DSTree<Word> wordIndex;

    buildIndexes(authorIndex, wordIndex);
}

/**
 * loops through the document directory
 * parses each JSON file as it loops
 * populates both author and word indexes
 */

void buildIndexes(DSHashTable<string, Title> &authorIndex, DSTree<Word> &wordIndex)
{
    string filePath, paperID, directory = "/Users/kevinleong/Documents/cs2341_data";
    DIR *directoryPath;
    struct dirent *dirp;

    directoryPath = opendir(directory.c_str());

    if(directoryPath == nullptr)
    {
        cout << "Error opening file" << endl;
        exit(0);
    }

    dirp = readdir(directoryPath);
    dirp = readdir(directoryPath);

    while((dirp = readdir(directoryPath))) //loops through the directory of files
    {
        filePath = directory + "/" + dirp->d_name;

        Document doc;
        doc.Parse(getFile(filePath).c_str()); //parses json file into tree

        if(doc.IsObject()) //checks that the document begins with an object
        {
            if(doc.HasMember("paper_id")) //checks that the file has an ID
            {
                paperID = doc["paper_id"].GetString();
            }
            if(doc["metadata"].HasMember("authors")) //checks that the file has metadata member
            {
                for(int i = 0; i < doc["metadata"]["authors"].Size(); i++) //loops through the authors json array
                {
                    string author = doc["metadata"]["authors"][i]["last"].GetString(); //sets author name to last name from json

                    if(!authorIndex.find(author)) //if the author is not already in the table, adds author to table and adds id to title vector
                    {
                        Title title;
                        title.addTitle(paperID);
                        pair<string , Title> pair(author, title);
                        authorIndex.insert(pair);
                    }
                    else //if the author is already in the table then add the paper ID to the ID vector
                    {
                        authorIndex[author].addTitle(paperID);
                    }
                }
            }

            if(doc["metadata"].HasMember("abstract"))
            {
                for(int i = 0; i < doc["metadata"]["abstract"].Size(); i++)
                {
                    string abstract = doc["metadata"]["abstract"][i].GetString();
                    std::cout << abstract << std::endl;
                }
            }
        }
    }
}

/**
 * gets and returns the file path for each file in the directory
 */

string getFile(string &filePath)
{
    ifstream file;
    file.open(filePath.c_str());

    string json, line;
    while(getline(file, line))
    {
        json += line;
    }
    file.close();
    return json;
}