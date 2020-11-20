//
// Created by Sammy Timmins on 11/19/20.
//

#include "Index.h"

void removeTrainingPunct();

using namespace std;
using namespace rapidjson;
/**
 * Creates the filler words set
 */
void makeFillerSet(set<string> &fillerSet)
{
    string fillerWord;
    ifstream fin;
    fin.open("../stopwords.txt");

    while(getline(fin, fillerWord)){
        fillerSet.insert(fillerWord);
    }
}

/**
 * Removes the trailing Punctuation
 */
void removeTrainingPunct(string& word) {
    for(int i = word.length() - 1; i > 0; i--){
        if(ispunct(word[i])){
            word.erase(i, 1);
        } else {
            break;
        }
    }
}

/**
 * loops through the document directory
 * parses each JSON file as it loops
 * populates both author and word indexes
 */

void buildIndexes(DSHashTable<string, Title> &authorIndex, DSTree<Word> &wordIndex, string &path)
{
    string filePath, paperID;
    DIR *directoryPath;
    struct dirent *dirp;

    directoryPath = opendir(path.c_str());

    if(directoryPath == nullptr)
    {
        cout << "Error opening file" << endl;
        exit(0);
    }

    dirp = readdir(directoryPath);
    dirp = readdir(directoryPath);

    while((dirp = readdir(directoryPath))) //loops through the directory of files
    {
        filePath = path + "/" + dirp->d_name;

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

            /**
             * Creates a set of filler words
             */
            set<string> fillerSet;
            makeFillerSet(fillerSet);

            /**
             * Adding words from abstract
             */
            if(doc.HasMember("abstract"))
            {
                stringstream ss;
                for(int i = 0; i < doc["abstract"].Size(); i++)
                {
                    string abstract = doc["abstract"][i]["text"].GetString();
                    ss << abstract;

                    string singleWord;
                    while(getline(ss, singleWord, ' ')){
                        if((fillerSet.count(singleWord) == 0)){

                            removeTrainingPunct(singleWord);

                            Porter2Stemmer::stem(singleWord); //stemmer from: https://bitbucket.org/smassung/porter2_stemmer/src/master/

                            if(wordIndex.find(singleWord)){
                                wordIndex.get(singleWord).getTitleList()[paperID]++;
                            } else {
                                wordIndex.insert(singleWord);
                                wordIndex.get(singleWord).addPaperID(paperID);
                            }
                        }
                    }
                }
            }
            /**
             * Adding words from body text
             */
            if(doc.HasMember("body_text"))
            {
                stringstream ss;
                for(int i = 0; i < doc["body_text"].Size(); i++)
                {
                    string body = doc["body_text"][i]["text"].GetString();
                    ss << body;

                    string singleWord;
                    while(getline(ss, singleWord, ' ')){
                        if((fillerSet.count(singleWord) == 0)){

                            removeTrainingPunct(singleWord);

                            Porter2Stemmer::stem(singleWord); //stemmer from: https://bitbucket.org/smassung/porter2_stemmer/src/master/

                            if(wordIndex.find(singleWord)){
                                wordIndex.get(singleWord).getTitleList()[paperID]++;
                            } else {
                                wordIndex.insert(singleWord);
                                wordIndex.get(singleWord).addPaperID(paperID);
                            }
                        }
                    }
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