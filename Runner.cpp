//
// Created by Sammy Timmins on 11/16/20.
//

#include "Runner.h"

using namespace std;

void runSearchEngine()
{
    DSHashTable<string, vector<string>> authorIndex;
}

void buildIndex(DSHashTable<string, vector<string>> authorIndex)
{
    ifstream file;
    string filePath, directory = "../cs2341_data";
    DIR *directoryPath;
    struct dirent *dirp;

    directoryPath = opendir(directory.c_str());

    if(directoryPath == nullptr)
    {
        cout << "Error opening file" << endl;
        exit(0);
    }

    while((dirp = readdir(directoryPath)))
    {
        filePath = directory + "/" + dirp->d_name;
        file.open(filePath.c_str());

        

        file.close();
    }
}