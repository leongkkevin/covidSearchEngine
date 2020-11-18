//
// Created by Sammy Timmins on 11/16/20.
//

#ifndef SEARCH_ENGINE_AUTHOR_H
#define SEARCH_ENGINE_AUTHOR_H

#include <string>
#include <vector>

class Author
{
private:
    std::string firstName, lastName, suffix;
    std::vector<std::string> middleInitial;

public:
    Author();
    Author(std::string firstName, std::string lastName, std::vector<std::string> &middleInitial, std::string suffix);
    ~Author() = default;
    Author(Author &copy);
    Author& operator=(Author &copy);
    void setFirstName(std::string name);
    void setLastName(std::string name);
    void addMiddleInitial(std::string initial);
    void setSuffix(std::string suffix);
    std::string getFirstName();
    std::string getLastName();
    std::vector<std::string> getMiddleInitials();
    std::string getSuffix();
};

#endif //SEARCH_ENGINE_AUTHOR_H
