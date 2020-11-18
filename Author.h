//
// Created by Sammy Timmins on 11/16/20.
//

#ifndef SEARCH_ENGINE_AUTHOR_H
#define SEARCH_ENGINE_AUTHOR_H

#include <string>

class Author
{
private:
    std::string firstName, lastName, middleInitial, email, affiliation, suffix;

public:
    Author();
    Author(std::string firstName, std::string lastName, std::string middleInitial, std::string email, std::string affiliation, std::string suffix);
    ~Author() = default;
    Author(Author &copy);
    Author& operator=(Author &copy);
    void setFirstName(std::string name);
    void setLastName(std::string name);
    void setMiddleInitial(std::string initial);
    void setEmail(std::string address);
    void setAffiliation(std::string affiliation);
    void setSuffix(std::string suffix);
    std::string getFirstName();
    std::string getLastName();
    std::string getMiddleInitial();
    std::string getEmail();
    std::string getAffiliation();
    std::string getSuffix();
};

#endif //SEARCH_ENGINE_AUTHOR_H
