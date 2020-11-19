//
// Created by Sammy Timmins on 11/18/20.
//

#include "Title.h"

Title::Title(const Title &title)
{
    titles = title.titles;
}

Title &Title::operator=(const Title &title)
{
    titles = title.titles;
    return *this;
}

std::string Title::getTitleAt(int index)
{
    return titles.at(index);
}

std::vector<std::string> &Title::getTitles()
{
    return titles;
}

void Title::addTitle(std::string title)
{
    titles.push_back(title);
}

void Title::printTitles()
{
    for(int i = 0; i < titles.size(); i++)
    {
        std::cout << titles[i] << std::endl;
    }
}

std::ostream &operator<<(std::ostream &, const Title &title) {
    for(int i = 0; i < title.titles.size(); i++)
    {
        std::cout << title.titles[i] << std::endl;
    }

}
