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

        TreeNode(){
            this->payload = NULL;
            this->left = this->right = nullptr;
            this->height = NULL;
        }
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

        ~TreeNode(){
            delete this->left;
            delete this->right;
        }

        TreeNode &operator= (const TreeNode *&copy)
        {
            this->payload = copy->payload;
            this->left = copy->left;
            this->right = copy->right;
            this->height = copy->height;
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

    int getBalance(TreeNode<T>* node)
    {
        if(node->left && node->right != nullptr){
            return node->left->height - node->right->height;
        } else
        {
            return 0;
        }
    }

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

    TreeNode<T>* minNode(TreeNode<T>* node)
    {
        TreeNode<T>* curr = node;
        while(curr->left != nullptr)
        {
            curr = curr->left;
        }

        return curr;
    }

    TreeNode<T>* remove(T value, TreeNode<T> *node)
    {
        TreeNode<T>* temp;

        if (node == NULL)
        {
            return node;
        } else if(value < node->payload)
        {
            remove(value, node->left);
        } else if(value > node->payload)
        {
            remove (value, node->right);
        } else if(value == node->payload)
        {
            // node with only one child or no child
            if( (node->left == NULL) || (node->right == NULL) )
            {
                temp = node->left ? node->left :node->right;

                // No child case
                if (temp == NULL)
                {
                    temp = node;
                    node = NULL;
                }
                else
                {
                    *node = *temp;
                } // One child case

                delete temp;
            }
            else
            {
                // node with two children: Get the inorder
                // successor (smallest in the right subtree)
                temp = minNode(node->right);

                // Copy the inorder successor's
                // data to this node
                node->payload = temp->payload;
                node->height = temp->height;

                // Delete the inorder successor
                node->right = remove(temp->payload, node->right);
            }
        }

        // If the tree had only one node
        // then return
        if (node == NULL)
            return node;

        // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
        node->height = 1 + max(height(node->left),height(node->right));

        // STEP 3: GET THE BALANCE FACTOR OF
        // THIS NODE (to check whether this
        // node became unbalanced)
        int balance = getBalance(node);

        // If this node becomes unbalanced,
        // then there are 4 cases

        // Left Left Case
        if (balance > 1 && getBalance(node->left) >= 0)
            rotateWithRightChild(node);

        // Left Right Case
        if (balance > 1 && getBalance(node->left) < 0)
        {
            doubleWithRightChild(node);
//            node->left = rotateWithLeftChild(node->left);
//            return rotateWithRightChild(node);
        }

        // Right Right Case
        if (balance < -1 && getBalance(node->right) <= 0)
            rotateWithLeftChild(node);

        // Right Left Case
        if (balance < -1 && getBalance(node->right) > 0)
        {
            doubleWithLeftChild(node);
//            node->right = rightRotate(node->right);
//            return leftRotate(node);
        }

        return node;
    }

    int height(TreeNode<T> *t) const{
        return t == NULL ? -1 : t->height;
    }
    int max (int left, int right) const{
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
    void remove(T value);

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
void DSTree<T>::remove(T value) {
    if(this->numNode != 0){
        delete remove(value, this->root);
        this->numNode--;
    } else;
}

template<typename T>
int DSTree<T>::getNumNodes() {
    return this->numNode;
}



#endif //SEARCH_ENGINE_DSTREE_H

