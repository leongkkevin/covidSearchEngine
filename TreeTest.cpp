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
    intTree.insert(20);
    intTree.insert(6);
    intTree.insert(25);
    intTree.insert(19);

    //REQUIRE(intTree.get(5)->getHeight() == 1);
    intTree.get(2);

    intTree.remove(4);
    intTree.get(4);
    intTree.insert(3);
    intTree.remove(20);
    intTree.insert(21);


    DSTree<Word> wordTree;
    Word word1("Cap");
    Word word2("Bap");
    wordTree.insert(word1);
    wordTree.insert(word2);
    Word word3("Trees");
    Word word4("A");
    Word word5("Apple");
    wordTree.insert(word3);
    wordTree.insert(word4);
    wordTree.insert(word5);

}
