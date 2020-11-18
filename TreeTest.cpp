//
// Created by Kevin Leong on 11/15/20.
//

#include "catch.hpp"
#include "DSTree.h"
#include "Word.h"

TEST_CASE("Insert"){
    DSTree<int> intTree;
    intTree.insert(5);
    REQUIRE(intTree.getNumNodes() == 1);
    intTree.insert(4);
    intTree.insert(1);
    intTree.insert(7);
    REQUIRE(intTree.get(5)->getHeight() == 1);
    intTree.get(2);

    DSTree<Word> wordTree;

}
