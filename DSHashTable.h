//
// Created by Sammy Timmins on 11/15/20.
//

#ifndef SEARCH_ENGINE_DSHASHTABLE_H
#define SEARCH_ENGINE_DSHASHTABLE_H

#include <list>
#include <iostream>

template <typename Key, typename Value>
class DSHashTable
{
private:
    int size = 100000;
    int count = 0;
    std::list<std::pair<Key, Value>> *table = nullptr;

    int hashFunction(Key key);
    void resize();

public:
    DSHashTable();
    ~DSHashTable();
    DSHashTable(const DSHashTable &copy);
    DSHashTable& operator=(const DSHashTable &copy);
    Value& operator[](const Key &keyToGet);
    void insert(const std::pair<Key, Value> pair);
    void insert(const Key &key, const Value value);
    void remove(const std::pair<Key, Value> pair);
    std::pair<Key, Value>& get(const Key &keyToGet);
    bool find (const Key &keyToFind, const Value &valueToFind);
    int getSize();
    int getCount();
    int getHash(const Key &keyToGet);
};

/**
 * calculates the hash value of the key
 */
template <typename Key, typename Value>
int DSHashTable<Key, Value>::hashFunction(Key key)
{
    int toReturn = key % size;
    return toReturn;
}

/**
 * resize function
 * resizes the hash table when the proportion of count to size == 1
 * hash table size doubles
 */
template<typename Key, typename Value>
void DSHashTable<Key, Value>::resize()
{
    std::list<std::pair<Key, Value>> *temp = new std::list<std::pair<Key, Value>>[size];
    for(int i = 0; i < size; i++)
    {
        temp[i] = table[i];
    }

    int oldSize = size;
    size *= 2;
    delete [] table;
    count = 0;
    table = new std::list<std::pair<Key, Value>>[size];

    for(int i = 0; i < oldSize; i++)
    {
        typename std::list<std::pair<Key, Value>>::iterator it;
        for(it = temp[i].begin(); it != temp[i].end(); it++)
        {
            std::pair<Key, Value> rehash = *it;
            this->insert(rehash);
        }
    }
}

/**
 * default constructor
 * initializes hash table size to 100,000
 */
template <typename Key, typename Value>
DSHashTable<Key, Value>::DSHashTable()
{
    table = new std::list<std::pair<Key, Value>>[size];
}

/**
 * destructor
 */
template<typename Key, typename Value>
DSHashTable<Key, Value>::~DSHashTable()
{
    delete [] table;
}

/**
 * copy constructor
 */
template<typename Key, typename Value>
DSHashTable<Key, Value>::DSHashTable(const DSHashTable &copy)
{
    size = copy.size;
    count = copy.count;
    table = new std::list<std::pair<Key, Value>>[size];
    for(int i = 0; i < size; i++)
    {
        table[i] = copy.table[i];
    }
}

/**
 * overloaded assignment operator
 */
template<typename Key, typename Value>
DSHashTable<Key, Value> &DSHashTable<Key, Value>::operator=(const DSHashTable &copy)
{
    if(this != &copy)
    {
        if(count != 0)
        {
            delete this;
        }

        size = copy.size;
        count = copy.count;
        for(int i = 0; i < size; i++)
        {
            table[i] = copy.table[i];
        }
        return *this;
    }
}

template<typename Key, typename Value>
Value &DSHashTable<Key, Value>::operator[](const Key &keyToGet)
{
    int index = hashFunction(keyToGet);

    typename std::list<std::pair<Key, Value>>::iterator it;
    for(it = table[index].begin(); it != table[index].end(); it++)
    {
        if(keyToGet == it->first)
        {
            return it->second;
        }
    }

    std::pair<Key, Value> newPair;
    newPair.first = keyToGet;

    this->insert(newPair);
    return newPair.second;
}

template<typename Key, typename Value>
void DSHashTable<Key, Value>::insert(const std::pair<Key, Value> pair)
{
    int index = hashFunction(pair.first);

    table[index].push_back(pair);
    count++;

    if((double)count / (double)size == 1.0)
    {
        resize();
    }
}

template<typename Key, typename Value>
void DSHashTable<Key, Value>::insert(const Key &key, const Value value)
{
    std::pair<Key, Value> insert(key, value);
    this->insert(insert);
}

template<typename Key, typename Value>
void DSHashTable<Key, Value>::remove(const std::pair<Key, Value> pair)
{
    int index = hashFunction(pair.first);

    table[index].remove(pair);
    count--;
}

template<typename Key, typename Value>
std::pair<Key, Value>& DSHashTable<Key, Value>::get(const Key &keyToGet)
{
    int index = hashFunction(keyToGet);
    typename std::list<std::pair<Key, Value>>::iterator it;

    for(it = table[index].begin(); it != table[index].end(); it++)
    {
        if(keyToGet == it->first)
        {
            return *it;
        }
    }

    std::pair<Key, Value> newPair;
    newPair.first = keyToGet;

    this->insert(newPair);
    return newPair;
}

template<typename Key, typename Value>
bool DSHashTable<Key, Value>::find(const Key &keyToFind, const Value &valueToFind) {
    int index = hashFunction(keyToFind);
    std::pair<Key, Value> toFind(keyToFind, valueToFind);

    typename std::list<std::pair<Key, Value>>::iterator it;

    for(it = table[index].begin(); it != table[index].end(); it++)
    {
        if(keyToFind == it->first)
        {
            if(valueToFind == it->second)
            {
                return true;
            }
        }
    }
    return false;
}

template<typename Key, typename Value>
int DSHashTable<Key, Value>::getSize()
{
    return size;
}

template<typename Key, typename Value>
int DSHashTable<Key, Value>::getCount() {
    return count;
}

template<typename Key, typename Value>
int DSHashTable<Key, Value>::getHash(const Key &keyToGet)
{
    return hashFunction(keyToGet);
}

#endif //SEARCH_ENGINE_DSHASHTABLE_H
