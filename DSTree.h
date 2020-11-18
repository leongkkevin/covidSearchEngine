//
// Created by Kevin Leong on 11/15/20.
//

#ifndef SEARCH_ENGINE_DSTREE_H
#define SEARCH_ENGINE_DSTREE_H

template<typename T>

class DSTree {
private:

    template<typename Type>
    struct TreeNode {
        T payload;

        TreeNode* left;
        TreeNode* right;

        int height;

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

        TreeNode(const TreeNode &copy){
            this->payload = copy.payload;
            this->left = copy.left;
            this->right = copy.right;
            this->height = copy.height;
        }

        ~TreeNode() = default;

        TreeNode &operator= (const TreeNode &copy)
        {
            this->payload = copy.payload;
            this->left = copy.left;
            this->right = copy.right;
            this->height = copy.height;
        }

        T getPayload()
        {
            return this->payload;
        }

        int getHeight()
        {
            return this->height;
        }
    };

    /*===================================================================================================*/

    TreeNode<T> *root;
    int depth;
    int numNode;

    void insert(T value, TreeNode<T> *&newVal)
    {
        if(newVal == nullptr)
        {
            newVal = new TreeNode<T>(value, nullptr, nullptr);
        } else if(value < newVal->payload)
        {
            insert(value, newVal->left);

            if(height(newVal->left) - height(newVal->right) == 2)
            {
                //CASE 1
                if(value < newVal->left->payload)
                {
                    rotateWithLeftChild(newVal);
                } else //CASE 2
                {
                    doubleWithLeftChild(newVal);
                }
            }
        } else if(value > newVal->payload)
        {
            insert(value,  newVal->right);

            if(height(newVal->right) - height(newVal->left) == 2)
            {
                //CASE 3
                if(value > newVal->right->payload)
                {
                    rotateWithRightChild(newVal);
                } else //CASE 4
                {
                    doubleWithRightChild(newVal);
                }
            }
        } else;
        newVal->height = max(height(newVal->left),height(newVal->right)) + 1;
    }

    int height(TreeNode<T> *t) const{
        return t == NULL ? -1 : t->height;
    }
    int max (T left, T right) const{
        return left > right ? left : right;
    }

    void del(TreeNode<T> *&deleteNode)
    {
        if(deleteNode->left != nullptr)
        {
            del(deleteNode->left);
        }
        if(deleteNode->right != nullptr)
        {
            del(deleteNode->right);
        }

        delete deleteNode;
    }

    void rotateWithLeftChild(TreeNode<T> *&k2)
    {
        TreeNode<T> *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), k2->height) + 1;
        k2 = k1;
    }
    void doubleWithLeftChild(TreeNode<T> *&k3)
    {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }

    void rotateWithRightChild(TreeNode<T> *&k1)
    {
        TreeNode<T> *k2 = k1->right;
        k1->right= k2->left;
        k2->left= k1;
        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2->height = max(height(k2->right), k1->height) + 1;
        k1 = k2;
    }
    void doubleWithRightChild(TreeNode<T> *&k1)
    {
        rotateWithLeftChild(k1->right);
        rotateWithRightChild(k1);

    }

    TreeNode<T>* find(T value, TreeNode<T> *node) const{
        TreeNode<T>* returnNode;
        if(value < node->payload)
        {
            if(node->left != nullptr){
                returnNode = find(value, node->left);
            }

        } else if(value > node->payload)
        {
            if(node->right != nullptr){
                returnNode = find(value, node->right);
            }

        } else if(value == node->payload){
            returnNode = node;
        } else {
            returnNode = new TreeNode<T>(value);
        }

        return returnNode;
    }

public:

    DSTree<T>();
    ~DSTree<T>();

    void insert(T value);

    int getNumNodes();

    TreeNode<T>* get(T value){
        TreeNode<T> *toReturn = find(value, this->root);

        if(toReturn == nullptr){
            toReturn = new TreeNode<T>(value);
        } else;

        return toReturn;
    }

};

template<typename T>
DSTree<T>::DSTree()
{
    this->root = nullptr;
    this->depth = 0;
    this->numNode = 0;
}
template<typename T>
DSTree<T>::~DSTree<T>()
{
    if(this->numNode > 0)
    {
        del(this->root);
    } else;
}

template<typename T>
void DSTree<T>::insert(T value)
{
    if(this->numNode == 0) {
        this->root = new TreeNode<T>(value);
    }
    else
    {
        insert(value, this->root);
    }
    this->numNode++;
}

template<typename T>
int DSTree<T>::getNumNodes() {
    return this->numNode;
}


#endif //SEARCH_ENGINE_DSTREE_H

