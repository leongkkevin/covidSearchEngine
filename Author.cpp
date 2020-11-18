//
// Created by Sammy Timmins on 11/16/20.
//

#include "Author.h"

Author::Author()
{
    firstName = "";
    lastName = "";
    suffix = "";
}

Author::Author(std::string firstName, std::string lastName, std::vector<std::string> &middleInitial, std::string suffix)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->middleInitial = middleInitial;
    this->suffix = suffix;
}

Author::Author(Author &copy)
{
    firstName = copy.firstName;
    lastName = copy.lastName;
    middleInitial = copy.middleInitial;
    suffix = copy.suffix;
}

Author &Author::operator=(Author &copy)
{
    firstName = copy.firstName;
    lastName = copy.lastName;
    middleInitial = copy.middleInitial;
    suffix = copy.suffix;

    return *this;
}

void Author::setFirstName(std::string name)
{
    firstName = name;
}

void Author::setLastName(std::string name)
{
    lastName = name;
}

void Author::addMiddleInitial(std::string initial)
{
    middleInitial.push_back(initial);
}

void Author::setSuffix(std::string suffix)
{
    this->suffix = suffix;
}

std::string Author::getFirstName()
{
    return firstName;
}

std::string Author::getLastName()
{
    return lastName;
}

std::vector<std::string> Author::getMiddleInitials()
{
    return middleInitial;
}

std::string Author::getSuffix()
{
    return suffix;
}

