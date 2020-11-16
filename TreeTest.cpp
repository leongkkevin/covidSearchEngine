//
// Created by Kevin Leong on 11/15/20.
//

#include "catch.hpp"
#include "DSTree.h"

TEST_CASE("Binary Tree"){
    DSTree<int> TestTree;
    TestTree.insert(5);
    TestTree.insert(2);
    TestTree.insert(9);
}