//
// Created by Sammy Timmins on 11/16/20.
//

#include "Runner.h"

using namespace std;
using namespace rapidjson;

void runSearchEngine()
{
    DSHashTable<Author, vector<string>> authorIndex;
    DSTree<Word> wordIndex;

    buildIndexes(authorIndex, wordIndex);
}

void buildIndexes(DSHashTable<Author, vector<string>> &authorIndex, DSTree<Word> &wordIndex)
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
                    Author author;
                    author.setFirstName(doc["metadata"]["authors"][i]["first"].GetString());
                    if(doc["metadata"]["authors"][i]["middle"].Size() > 0)
                    {
                        for(int j = 0; j < doc["metadata"]["authors"][i]["middle"].Size(); j++)
                        {
                            author.addMiddleInitial(doc["metadata"]["authors"][i]["middle"][j].GetString());
                        }
                    }
                    else
                    {
                        author.addMiddleInitial("");
                    }
                    author.setLastName(doc["metadata"]["authors"][i]["last"].GetString());
                    author.setSuffix(doc["metadata"]["authors"][i]["suffix"].GetString());
                    cout << author.getFirstName() << " ";
                    for(int i = 0; i < author.getMiddleInitials().size(); i++)
                    {
                        cout << author.getMiddleInitials().at(i) << ". ";
                    }
                    //authorIndex
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