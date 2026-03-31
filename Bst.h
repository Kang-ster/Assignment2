#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include <iostream>

using std::istream;
using std::ostream;

template <class T>
struct Node{
    T data;
    Node<T> *left;
    Node<T> *right;
};

template <class T>
class Bst{
public:
    ///Default constructor. Sets member m_root to nullptr. <p> Functions such as Insert will create the appropriate memory when necessary.
    Bst();
    ///Deep Copy Constructor
    Bst(const Bst& toCopy);
    ///Destructor. Uses DeleteTree() function to delete the entire BST when it goes out of scope.
    ~Bst();

    /** @brief Insert - Inserts the parameter at an appropriate location in the BST.
    *
    * @return bool
    * @details Calls the private method PrivateInsert() using the m_root node. <p>
    * Recursively runs through the entire tree to find an appropriate location to insert. <p>
    * If inserted successfully, returns true.
    */
    bool Insert(const T item);

    /** @brief Search - Finds if the parameter is present in the BST
    *
    * @param int num (for integer Bst)
    * @return void
    * @details Employs depth first search to look for the parameter. Prints out to screen whether the item is found.
    */
    void Search(const T item); //depth first search to find if the content is in the tree

    ///overloaded Search
    void Search(const T item, void (*visit) (T&));

    /** @brief inOrder - Prints out the contents of the tree in In-Order Traversal
    *
    * @return void
    * @details Calls the private method inOrderTraversal() using the m_root node. <p>
    * Recursively runs through the entire tree to print out the contents.
    */
    void InOrder() const;

    ///overloaded inOrder
    void InOrder(void (*visit) (T&)) const;

    /** @brief preOrder - Prints out the contents of the tree in Pre-Order Traversal
    *
    * @return void
    * @details Calls the private method preOrderTraversal() using the m_root node. <p>
    * Recursively runs through the entire tree to print out the contents.
    */
    void PreOrder() const;

    ///overloaded preOrder
    void PreOrder(void (*visit) (T&)) const;

    /** @brief postOrder - Prints out the contents of the tree in Post-Order Traversal
    *
    * @return void
    * @details Calls the private method postOrderTraversal() using the m_root node. <p>
    * Recursively runs through the entire tree to print out the contents.
    */
    void PostOrder() const;

    ///overloaded postOrder
    void PostOrder(void (*visit) (T&)) const;

    void PrintOstream(ostream& os, const Bst<T>& bst);

private:
    ///m_root is a Node pointer. Node is a struct which contains data, left Node*, and right Node*
    Node<T> *m_root;

    //private functions for BST
    /** @brief PrivateCopyTree - Helper method for Deep Copy
    *
    * @return Node*
    * @details Copies current m_root. <p>
    * Recursively calls itself and runs through the tree (preOrder) to copy each valid node. <p>
    * Returns the Node* to itself when successful.
    */
    Node<T>* PrivateCopyTree(Node<T> * nptr);

    /** @brief PrivateInsert - Inserts a new node at the sorted location.
    *
    * @return Node*
    * @details Checks if current m_root is a valid location to insert. If not, compares the value of the input and uses either left or right child node. <p>
    * Recursively calls itself and runs through the tree to find an appropriate location. <p>
    * Returns the Node* to itself when successful.
    */
    Node<T>* PrivateInsert(Node<T> * nptr, const T item);

    /** @brief DeleteTree - Deletes and frees the memory for the entire BST.
    *
    * @return void
    * @details Calls the private method DeleteNode() using the m_root node. <p>
    * Recursively runs through the entire tree, freeing memory from the bottom.
    */
    void DeleteTree();

    /** @brief DeleteNode - Helper for DeleteTree(). Deletes the Node at the address passed via parameter.
    *
    * @return void
    * @details Will delete the contents of the node (i.e. left and right pointers), followed by itself. <p>
    * Will call to delete children nodes recursively. <p>
    * If m_root is not null, deletes it and frees the memory before setting it to nullptr.
    */
    void DeleteNode(Node<T> * &nptr);

    /** @brief PrivateSearch - Recursive function used by Search().
    *
    * @return bool
    * @details Checks if the current pointer's data matches the parameter data. If not, recursively calls itself to check left and right nodes. <p>
    * Uses boolean to determine if the data is found or not.
    */
    bool PrivateSearch(Node<T> *nptr, const T item);

    ///overloaded PrivateSearch
    bool PrivateSearch(Node<T> *nptr, const T item, void (*visit) (T&));

    /** @brief inOrderTraversal - Private helper of inOrder()
    *
    * @return void
    * @details Calls itself recursively, checking left Node, data, then right Node respectively.
    */
    void InOrderTraversal(Node<T> *nptr) const;

    ///overloaded private inOrder
    void InOrderTraversal(Node<T> *nptr, void (*visit) (T&)) const;

    /** @brief preOrderTraversal - Private helper of preOrder()
    *
    * @return void
    * @details Calls itself recursively, checking data, left Node, then right Node respectively.
    */
    void PreOrderTraversal(Node<T> *nptr) const;

    ///overloaded preOrderTraversal
    void PreOrderTraversal(Node<T> *nptr, void (*visit) (T&)) const;

    /** @brief postOrderTraversal - Private helper of postOrder()
    *
    * @return void
    * @details Calls itself recursively, checking left Node, right Node, then data respectively.
    */
    void PostOrderTraversal(Node<T> *nptr) const;

    ///overloaded postOrderTraversal
    void PostOrderTraversal(Node<T> *nptr, void (*visit) (T&)) const;

    void PrivatePrintOstream(Node<T> *nptr, ostream os);
};

template <class T>
Bst<T>::Bst()
{
    m_root = nullptr;
}

template <class T>
Bst<T>::Bst(const Bst& toCopy)
{
    this->m_root = PrivateCopyTree(toCopy.m_root);
}

template <class T>
Bst<T>::~Bst()
{
    DeleteTree();
}

template <class T>
Node<T>* Bst<T>::PrivateCopyTree(Node<T> * nptr)
{
    if (nptr == nullptr)
    {
        return nptr;
    }

    Node<T>* tempNode = new Node<T>;
    tempNode->data = nptr->data; //copy current
    //recursively call left & right
    tempNode->left = PrivateCopyTree(nptr->left);
    tempNode->right = PrivateCopyTree(nptr->right);

    return tempNode;
}

// ---Recursive version of Insert---
template <class T>
bool Bst<T>::Insert(const T item)
{
    m_root = PrivateInsert(m_root, item);
    return true;
}

template <class T>
Node<T>* Bst<T>::PrivateInsert(Node<T> * nptr, const T item)
{
    //end condition: current node is null
    if (nptr == nullptr)
    {
        Node<T>* tempNode = new Node<T>; //allocate new memory for the node
        tempNode->data = item; //set item
        tempNode->left = nullptr;
        tempNode->right = nullptr;
        return tempNode;
    }
    //else(not null):
    if (nptr->data == item) //check for dupes
    {
        std::cout<<"[Item "<<item<<" is a duplicate and was not inserted]"<<std::endl;
        return nptr; //returns itself if not found; cancels the search
    }
    else
    {
        //if greater than, go right,
        //if less than, go left
        if (item > nptr->data)
        {
            nptr->right = PrivateInsert(nptr->right, item);
            return nptr;
        }
        else
        {
            nptr->left = PrivateInsert(nptr->left, item);
            return nptr;
        }
    }
}

template <class T>
void Bst<T>::DeleteTree()
{
    DeleteNode(m_root);
}

// ---Iterative version of Insert (intBst)---
//bool intBst::Insert(const int num)
//{
//    //create new node
//    Node *current; //node for traversal
//    Node *trailcurrent = nullptr;
//    Node *newNode; //pointer for new node
//
//    newNode = new Node; //memory created for new node
//    newNode->data = num; //assign newNode's data as int parameter
//    newNode->left = nullptr; //assign left and right ptrs
//    newNode->right = nullptr; //as null
//
//    if (this->m_root == nullptr) //if current node is empty
//    {
//        this->m_root = newNode; //assign newNode to the current location
//    }
//    else
//    {
//        current = this->m_root; //set the current position
//        while (current != nullptr)
//        {
//            trailcurrent=current; //"save" the current position in trailcurrent; current may need to move
//            if (current->data == num) //if duplicate, do nothing
//            {
//                return false; //exit the function
//            }
//            else if (current->data > num) //if num is smaller, go left
//            {
//                current = current->left; //"move" to the left
//            }
//            else
//            {
//                current = current->right; //"move to the right
//            }
//        } //this while loop will continue until a nullptr is found, i.e. empty space in tree
//        //while loop exited; current node is nullptr
//        //use trailcurrent (which was where current is) to insert into the position (using the same comparison)
//        if (trailcurrent->data > num)
//        {
//            trailcurrent->left = newNode;
//        }
//        else
//        {
//            trailcurrent->right = newNode;
//        }
//    }
//    return true;
//}

template <class T>
void Bst<T>::DeleteNode(Node<T> * &nptr)
{
    if (nptr != nullptr)
    {
        //check each side
        DeleteNode(nptr->left);
        DeleteNode(nptr->right);

        delete nptr;
        nptr = nullptr;
    }
}

template <class T>
void Bst<T>::Search(const T item)
{
    if (PrivateSearch(m_root, item))
        std::cout << item << " was found in the BST. " << std::endl;
    else
        std::cout << item << " was NOT found. " << std::endl;
}

template <class T>
bool Bst<T>::PrivateSearch(Node<T> *nptr, const T item)
{
    //exit condition; nptr is null
    if (nptr == nullptr)
        return false;

    bool found = false;
    if (item == nptr->data)
    {
        found = true;
        //can retrieve data
    }
    if (!found && item<m_root->data)
    {
        found = PrivateSearch(nptr->left, item);
    }
    if (!found && item>m_root->data)
    {
        found = PrivateSearch(nptr->right, item);
    }

    return found;
}

template <class T>
void Bst<T>::Search(const T item, void (*visit) (T&))
{
    if (!PrivateSearch(m_root, item, visit))
    {
        std::cout << item << " was NOT found. Function was not run. " << std::endl;
    }
}

template <class T>
bool Bst<T>::PrivateSearch(Node<T> *nptr, const T item, void (*visit) (T&))
{
    //exit condition; nptr is null
    if (nptr == nullptr)
        return false;

    bool found = false;
    if (item == nptr->data)
    {
        found = true;
        //can retrieve data
        (*visit)(nptr->data);
    }
    if (!found && item<m_root->data)
    {
        found = PrivateSearch(nptr->left, item, visit);
    }
    if (!found && item>m_root->data)
    {
        found = PrivateSearch(nptr->right, item, visit);
    }

    return found;
}

template <class T>
void Bst<T>::InOrder() const
{
    std::cout<<"DEBUG: inorder called" << std::endl;
    InOrderTraversal(m_root);
}

template <class T>
void Bst<T>::InOrder(void (*visit) (T&)) const
{
    InOrderTraversal(m_root, *visit);
}

template <class T>
void Bst<T>::InOrderTraversal (Node<T> *nptr) const
{
    if (nptr != nullptr)
    {
        InOrderTraversal(nptr->left);//print left
        std::cout << nptr->data << " ";//print current
        InOrderTraversal(nptr->right);//print right
    }
}

template <class T>
void Bst<T>::InOrderTraversal(Node<T> *nptr, void (*visit) (T&)) const
{
    if (nptr != nullptr)
    {
        InOrderTraversal(nptr->left, *visit);//print left
        (*visit)(nptr->data);
        InOrderTraversal(nptr->right, *visit);//print right
    }
}

template <class T>
void Bst<T>::PreOrder () const
{
    PreOrderTraversal(m_root);
}

template <class T>
void Bst<T>::PreOrder (void (*visit) (T&)) const
{
    PreOrderTraversal(m_root, *visit);
}

template <class T>
void Bst<T>::PreOrderTraversal (Node<T> *nptr) const
{
    if (nptr != nullptr)
    {
        std::cout << nptr->data << " ";//print current
        PreOrderTraversal(nptr->left);//print left
        PreOrderTraversal(nptr->right);//print right
    }
}

template <class T>
void Bst<T>::PreOrderTraversal (Node<T> *nptr, void (*visit) (T&)) const
{
    if (nptr != nullptr)
    {
        (*visit)(nptr->data);//access data
        PreOrderTraversal(nptr->left, *visit);//print left
        PreOrderTraversal(nptr->right, *visit);//print right
    }
}

template <class T>
void Bst<T>::PostOrder() const
{
    PostOrderTraversal(m_root);
}

template <class T>
void Bst<T>::PostOrder(void (*visit) (T&)) const
{
    PostOrderTraversal(m_root, *visit);
}

template <class T>
void Bst<T>::PostOrderTraversal (Node<T> *nptr) const
{
    if (nptr != nullptr)
    {
        PostOrderTraversal(nptr->left);//print left
        PostOrderTraversal(nptr->right);//print right
        std::cout << nptr->data << " ";//print current
    }
}

template <class T>
void Bst<T>::PostOrderTraversal (Node<T> *nptr, void (*visit) (T&)) const
{
    if (nptr != nullptr)
    {
        PostOrderTraversal(nptr->left, *visit);//print left
        PostOrderTraversal(nptr->right, *visit);//print right
        (*visit)(nptr->data);//access data
    }
}

template <class T>
void Bst<T>::PrintOstream(ostream& os, const Bst<T>& bst)
{
    PrivatePrintOstream(bst.m_root, os);
}

template <class T>
void Bst<T>::PrivatePrintOstream(Node<T> *nptr, ostream os)
{
    if (nptr != nullptr)
    {
        PrintOstream(nptr->left, os);//print left
        os << nptr->data << '\n';
        PrintOstream(nptr->right, os);//print right
    }
}

//ostream & operator << (ostream& os, const Bst<class T>& bst)
//{
//        bst.PrintOstream(os, bst);
//        return os;
//}


#endif // BST_H_INCLUDED
