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
