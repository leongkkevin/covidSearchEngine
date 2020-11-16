//
// Created by Kevin Leong on 11/15/20.
//

#ifndef SEARCH_ENGINE_DSTREE_H
#define SEARCH_ENGINE_DSTREE_H

template<typename T>

class DSTree {
private:

    template<typename Type>
    class TreeNode {
    private:
        T payload;

        TreeNode* left;
        TreeNode* right;

        int height;

    public:
        TreeNode() = default;
        TreeNode(T value){
            this->payload = value;
            this->left = nullptr;
            this->right = nullptr;
            this->height = 0;
        }
        TreeNode(T value, TreeNode* left, TreeNode* right){
            this->payload = value;
            this->left = left;
            this->right = right;
        }
        TreeNode(const TreeNode &copy);
        ~TreeNode();

        TreeNode &operator= (const TreeNode &copy);
    };

    /*===================================================================================================*/

    TreeNode<T> head;
    int depth;
    int numNode;

    void insert(T value, TreeNode<T> *&newVal){
        if(newVal == nullptr){
            newVal = new TreeNode<T>(value, nullptr, nullptr);
        } else if(value < newVal->payload){
            insert(value, newVal->left);
        } else if(value > newVal->payload){
            insert(value,  newVal->right);
        } else;
    }

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
    if(this->numNode == 0) {
        this->head = new TreeNode<T>(value);
        this->numNode++;
    }
    else
    {

    }
}


#endif //SEARCH_ENGINE_DSTREE_H
