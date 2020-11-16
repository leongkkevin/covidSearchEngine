//
// Created by Sammy Timmins on 11/14/20.
//
#define CATCH_CONFIG_RUNNER

#include <iostream>
#include "catch.hpp"

int runCatchTests(int argc, char* const argv[])
{
    return Catch::Session().run(argc, argv);
}

int main(int argc, char** argv)
{
    if(strcmp(argv[1], "-test") == 0)
    {
        return runCatchTests(1, argv);
    }

    return 0;
}

