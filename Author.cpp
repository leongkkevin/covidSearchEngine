//
// Created by Sammy Timmins on 11/16/20.
//

#include "Author.h"

Author::Author()
{
    firstName = "";
    lastName = "";
    middleInitial = "";
    email = "";
    affiliation = "";
    suffix = "";
}

Author::Author(std::string firstName, std::string lastName, std::string middleInitial, std::string email,
               std::string affiliation, std::string suffix)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->middleInitial = middleInitial;
    this->email = email;
    this->affiliation = affiliation;
    this->suffix = suffix;
}

Author::Author(Author &copy)
{
    firstName = copy.firstName;
    lastName = copy.lastName;
    middleInitial = copy.middleInitial;
    email = copy.email;
    affiliation = copy.affiliation;
    suffix = copy.suffix;
}

Author &Author::operator=(Author &copy)
{
    firstName = copy.firstName;
    lastName = copy.lastName;
    middleInitial = copy.middleInitial;
    email = copy.email;
    affiliation = copy.affiliation;
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

void Author::setMiddleInitial(std::string initial)
{
    middleInitial = initial;
}

void Author::setEmail(std::string address)
{
    email = address;
}

void Author::setAffiliation(std::string affiliation)
{
    this->affiliation = affiliation;
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

std::string Author::getMiddleInitial()
{
    return middleInitial;
}

std::string Author::getEmail()
{
    return email;
}

std::string Author::getAffiliation()
{
    return affiliation;
}

std::string Author::getSuffix()
{
    return suffix;
}

