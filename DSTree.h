//
// Created by Kevin Leong on 11/15/20.
//

#ifndef SEARCH_ENGINE_DSTREE_H
#define SEARCH_ENGINE_DSTREE_H

template <typename T>

class TreeNode {
private:
    T payload;

    T* left;
    T* right;

public:
    TreeNode();
    TreeNode(T value);
    TreeNode(const TreeNode &copy);
    ~TreeNode();

    TreeNode &operator= (const TreeNode &copy);
};

template<typename T>
TreeNode<T>::TreeNode() {
}

template<typename T>
TreeNode<T>::TreeNode(T value) {
    this->payload = value;
    this->left = nullptr;
    this->right = nullptr;
}

/*===================================================================================================*/

template<typename T>

class DSTree {
private:
    TreeNode<T> head;
    int depth;
    int numNode;
public:

    DSTree<T>();
    ~DSTree<T>();

    void insert(T value);
};

template<typename T>
DSTree<T>::DSTree()
{
    this->head = nullptr;
    this->depth = 0;
    this->numNode = 0;
}

template<typename T>
void DSTree<T>::insert(T value)
{
    TreeNode<T> newValue = new TreeNode<T>(value);
    if(this->numNode == 0)
    {
        this->head = newValue;
        this->numNode++;
        this->depth++;
    }else if(head)
    {

    }
}


#endif //SEARCH_ENGINE_DSTREE_H
