//
// Created by Sammy Timmins on 11/14/20.
//
#define CATCH_CONFIG_RUNNER

#include <iostream>
#include "catch.hpp"
#include "Runner.h"

int runCatchTests(int argc, char* const argv[])
{
    return Catch::Session().run(argc, argv);
}

int main(int argc, char** argv)
{
    auto start = std::chrono::high_resolution_clock::now();
    if(argc == 3)
    {
        string search = argv[1];
        string path = argv[2];
        runSearchEngine(search, path);
    }
    else if(argc == 1)
    {
        runSearchEngine();
    }
    else if(strcmp(argv[1], "-test") == 0)
    {
        return runCatchTests(1, argv);
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << duration.count() << " microseconds" << endl;
    return 0;
}

