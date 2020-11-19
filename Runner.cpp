//
// Created by Sammy Timmins on 11/16/20.
//

#include "Runner.h"

using namespace std;
using namespace rapidjson;

void runSearchEngine()
{
    DSHashTable<string, Title> authorIndex;
    DSTree<Word> wordIndex;

    buildIndexes(authorIndex, wordIndex);
}

void buildIndexes(DSHashTable<string, Title> &authorIndex, DSTree<Word> &wordIndex)
{
    string filePath, paperID, directory = "/Users/stimmins/Documents/cs2341_data";
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

    while((dirp = readdir(directoryPath)))
    {
        filePath = directory + "/" + dirp->d_name;

        Document doc;
        doc.Parse(getFile(filePath).c_str());

        if(doc.IsObject())
        {
            if(doc.HasMember("paper_id"))
            {
                paperID = doc["paper_id"].GetString();
            }
            if(doc["metadata"].HasMember("authors"))
            {
                for(int i = 0; i < doc["metadata"]["authors"].Size(); i++)
                {
                    string author;
                    author = author + doc["metadata"]["authors"][i]["first"].GetString() + " ";

                    if(doc["metadata"]["authors"][i]["middle"].Size() > 0)
                    {
                        for(int j = 0; j < doc["metadata"]["authors"][i]["middle"].Size(); j++)
                        {
                            author = author + doc["metadata"]["authors"][i]["middle"][j].GetString() + ". ";
                        }
                    }

                    author = author + doc["metadata"]["authors"][i]["last"].GetString();
                    author = author + doc["metadata"]["authors"][i]["suffix"].GetString();

                    if(!authorIndex.find(author))
                    {
                        Title title;
                        title.addTitle(paperID);
                        pair<string , Title> pair(author, title);
                    }
                    else
                    {
                        authorIndex[author].addTitle(paperID);
                    }
                }
            }
        }
    }
}

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