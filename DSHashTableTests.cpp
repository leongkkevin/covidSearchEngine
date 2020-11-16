//
// Created by Sammy Timmins on 11/15/20.
//

#include "catch.hpp"
#include "DSHashTable.h"

TEST_CASE("DSHashTable Tests with primitive data types")
{
    DSHashTable<int, int> integers;
    DSHashTable<int, char> intAndChar;
    DSHashTable<char, int> charAndInt;

    for(int i = 1; i <= 10; i++)
    {
        std::pair<int, int> insert(i, i);
        integers.insert(insert);
    }

    int x = 11;
    for(int i = 100001; i <= 100010; i++)
    {
        std::pair<int, int> insert(i, x);
        integers.insert(insert);
        x++;
    }

    char loop = 'a';
    for(int i = 1; i <= 10; i++)
    {
        std::pair<int, char> insert(i, loop);
        intAndChar.insert(insert);
        loop++;
    }

    for(int i = 100001; i <= 100010; i++)
    {
        std::pair<int, char> insert(i, loop);
        intAndChar.insert(insert);
        loop++;
    }

    x = 1;
    for(char i = 'a'; i <= 'j'; i++)
    {
        std::pair<char, int> insert(i, x);
        charAndInt.insert(insert);
        x++;
    }

    SECTION("insert() and get() with primitives")
    {
        REQUIRE((integers.get(1).second == 1));
        REQUIRE((integers.get(2).second == 2));
        REQUIRE((integers.get(3).second == 3));
        REQUIRE((integers.get(4).second == 4));
        REQUIRE((integers.get(5).second == 5));
        REQUIRE((integers.get(6).second == 6));
        REQUIRE((integers.get(7).second == 7));
        REQUIRE((integers.get(8).second == 8));
        REQUIRE((integers.get(9).second == 9));
        REQUIRE((integers.get(10).second == 10));
        REQUIRE((integers.get(100001).second == 11));
        REQUIRE((integers.get(100002).second == 12));
        REQUIRE((integers.get(100003).second == 13));
        REQUIRE((integers.get(100004).second == 14));
        REQUIRE((integers.get(100005).second == 15));
        REQUIRE((integers.get(100006).second == 16));
        REQUIRE((integers.get(100007).second == 17));
        REQUIRE((integers.get(100008).second == 18));
        REQUIRE((integers.get(100009).second == 19));
        REQUIRE((integers.get(100010).second == 20));

        REQUIRE((intAndChar.get(1).second == 'a'));
        REQUIRE((intAndChar.get(2).second == 'b'));
        REQUIRE((intAndChar.get(3).second == 'c'));
        REQUIRE((intAndChar.get(4).second == 'd'));
        REQUIRE((intAndChar.get(5).second == 'e'));
        REQUIRE((intAndChar.get(6).second == 'f'));
        REQUIRE((intAndChar.get(7).second == 'g'));
        REQUIRE((intAndChar.get(8).second == 'h'));
        REQUIRE((intAndChar.get(9).second == 'i'));
        REQUIRE((intAndChar.get(10).second == 'j'));
        REQUIRE((intAndChar.get(100001).second == 'k'));
        REQUIRE((intAndChar.get(100002).second == 'l'));
        REQUIRE((intAndChar.get(100003).second == 'm'));
        REQUIRE((intAndChar.get(100004).second == 'n'));
        REQUIRE((intAndChar.get(100005).second == 'o'));
        REQUIRE((intAndChar.get(100006).second == 'p'));
        REQUIRE((intAndChar.get(100007).second == 'q'));
        REQUIRE((intAndChar.get(100008).second == 'r'));
        REQUIRE((intAndChar.get(100009).second == 's'));
        REQUIRE((intAndChar.get(100010).second == 't'));

        REQUIRE((charAndInt.get('a').second == 1));
        REQUIRE((charAndInt.get('b').second == 2));
        REQUIRE((charAndInt.get('c').second == 3));
        REQUIRE((charAndInt.get('d').second == 4));
        REQUIRE((charAndInt.get('e').second == 5));
        REQUIRE((charAndInt.get('f').second == 6));
        REQUIRE((charAndInt.get('g').second == 7));
        REQUIRE((charAndInt.get('h').second == 8));
        REQUIRE((charAndInt.get('i').second == 9));
        REQUIRE((charAndInt.get('j').second == 10));

        integers.get(1).second = 2;
        intAndChar.get(1).second = 'b';
        charAndInt.get('a').second = 2;

        REQUIRE((integers.get(1).second == 2));
        REQUIRE((intAndChar.get(1).second == 'b'));
        REQUIRE((charAndInt.get('a').second == 2));
    }

    SECTION("Overloaded [] operator")
    {
        REQUIRE((integers[1] == 1));
        REQUIRE((integers[2] == 2));
        REQUIRE((integers[3] == 3));
        REQUIRE((integers[4] == 4));
        REQUIRE((integers[5] == 5));
        REQUIRE((integers[6] == 6));
        REQUIRE((integers[7] == 7));
        REQUIRE((integers[8] == 8));
        REQUIRE((integers[9] == 9));
        REQUIRE((integers[10] == 10));
        REQUIRE((integers[100001] == 11));
        REQUIRE((integers[100002] == 12));
        REQUIRE((integers[100003] == 13));
        REQUIRE((integers[100004] == 14));
        REQUIRE((integers[100005] == 15));
        REQUIRE((integers[100006] == 16));
        REQUIRE((integers[100007] == 17));
        REQUIRE((integers[100008] == 18));
        REQUIRE((integers[100009] == 19));
        REQUIRE((integers[100010] == 20));

        REQUIRE((intAndChar[1] == 'a'));
        REQUIRE((intAndChar[2] == 'b'));
        REQUIRE((intAndChar[3] == 'c'));
        REQUIRE((intAndChar[4] == 'd'));
        REQUIRE((intAndChar[5] == 'e'));
        REQUIRE((intAndChar[6] == 'f'));
        REQUIRE((intAndChar[7] == 'g'));
        REQUIRE((intAndChar[8] == 'h'));
        REQUIRE((intAndChar[9] == 'i'));
        REQUIRE((intAndChar[10] == 'j'));
        REQUIRE((intAndChar[100001] == 'k'));
        REQUIRE((intAndChar[100002] == 'l'));
        REQUIRE((intAndChar[100003] == 'm'));
        REQUIRE((intAndChar[100004] == 'n'));
        REQUIRE((intAndChar[100005] == 'o'));
        REQUIRE((intAndChar[100006] == 'p'));
        REQUIRE((intAndChar[100007] == 'q'));
        REQUIRE((intAndChar[100008] == 'r'));
        REQUIRE((intAndChar[100009] == 's'));
        REQUIRE((intAndChar[100010] == 't'));

        REQUIRE((charAndInt['a'] == 1));
        REQUIRE((charAndInt['b'] == 2));
        REQUIRE((charAndInt['c'] == 3));
        REQUIRE((charAndInt['d'] == 4));
        REQUIRE((charAndInt['e'] == 5));
        REQUIRE((charAndInt['f'] == 6));
        REQUIRE((charAndInt['g'] == 7));
        REQUIRE((charAndInt['h'] == 8));
        REQUIRE((charAndInt['i'] == 9));
        REQUIRE((charAndInt['j'] == 10));

        integers[1] = 2;
        intAndChar[1] = 'b';
        charAndInt['a'] = 2;

        REQUIRE((integers[1] == 2));
        REQUIRE((intAndChar[1] == 'b'));
        REQUIRE((charAndInt['a'] == 2));
    }

    SECTION("find() with primitives")
    {
        REQUIRE((integers.find(1, 1)));
        REQUIRE(!(integers.find(11, 1)));
        REQUIRE(!(integers.find(1, 2)));

        REQUIRE((intAndChar.find(1, 'a')));
        REQUIRE(!(intAndChar.find(11, 'a')));
        REQUIRE(!(intAndChar.find(1, 'b')));

        REQUIRE((charAndInt.find('a', 1)));
        REQUIRE(!(charAndInt.find('z', 1)));
        REQUIRE(!(charAndInt.find('a', 2)));
    }

    SECTION("remove() with primitives")
    {
        std::pair<int, int> removeIntegers(1,1);
        integers.remove(removeIntegers);
        REQUIRE(!(integers.find(1,1)));
        REQUIRE((integers.getCount() == 19));

        std::pair<int, char> removeIntAndChar(1, 'a');
        intAndChar.remove(removeIntAndChar);
        REQUIRE(!(intAndChar.find(1, 'a')));
        REQUIRE((intAndChar.getCount() == 19));

        std::pair<char, int> removeCharAndInt('a', 1);
        charAndInt.remove(removeCharAndInt);
        REQUIRE(!(charAndInt.find('a', 1)));
        REQUIRE((charAndInt.getCount() == 9));
    }

    SECTION("getSize() with primitives")
    {
        REQUIRE((integers.getSize() == 100000));
        REQUIRE((intAndChar.getSize() == 100000));
        REQUIRE((charAndInt.getSize() == 100000));
    }

    SECTION("getCount() with primitives")
    {
        REQUIRE((integers.getCount() == 20));
        REQUIRE((intAndChar.getCount() == 20));
        REQUIRE((charAndInt.getCount() == 10));
    }

    SECTION("Copy constructor with primitives")
    {
        DSHashTable<int, int> integersCopy(integers);
        DSHashTable<int, char> intAndCharCopy(intAndChar);
        DSHashTable<char, int> charAndIntCopy(charAndInt);

        REQUIRE((integers.find(1, 1)));
        REQUIRE(!(integers.find(11, 1)));
        REQUIRE(!(integers.find(1, 2)));

        REQUIRE((intAndChar.find(1, 'a')));
        REQUIRE(!(intAndChar.find(11, 'a')));
        REQUIRE(!(intAndChar.find(1, 'b')));

        REQUIRE((charAndInt.find('a', 1)));
        REQUIRE(!(charAndInt.find('z', 1)));
        REQUIRE(!(charAndInt.find('a', 2)));
    }

    SECTION("Overloaded assignment operator with primitives")
    {
        DSHashTable<int, int> integersCopy;
        DSHashTable<int, char> intAndCharCopy;
        DSHashTable<char, int> charAndIntCopy;

        integersCopy = integers;
        intAndCharCopy = intAndChar;
        charAndIntCopy = charAndInt;

        REQUIRE((integers.find(1, 1)));
        REQUIRE(!(integers.find(11, 1)));
        REQUIRE(!(integers.find(1, 2)));

        REQUIRE((intAndChar.find(1, 'a')));
        REQUIRE(!(intAndChar.find(11, 'a')));
        REQUIRE(!(intAndChar.find(1, 'b')));

        REQUIRE((charAndInt.find('a', 1)));
        REQUIRE(!(charAndInt.find('z', 1)));
        REQUIRE(!(charAndInt.find('a', 2)));
    }
}