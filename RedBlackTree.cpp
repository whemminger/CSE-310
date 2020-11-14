//************************************************************************
// ASU CSE310 Assignment #6 Fall 2020
// Name of Author: William Schuhmann
// ASU ID: 1215016803
// Description: Red black tree implementation. See RedBlackTree.h
//              for the tree definition. You need to add your own
//              code at //---- position
//************************************************************************

#include "RedBlackTree.h"

using namespace std;

//*******************************************************************
//constructor
RedBlackTree::RedBlackTree()
{
    root = NULL;
}

//*******************************************************************
//destructor
RedBlackTree::~RedBlackTree()
{
    int nodeSize = deleteNode(root);
    cout << "The number of nodes deleted: " << nodeSize << endl;
}

//**************************************************************
//This function return the root of the red-black tree
Node* RedBlackTree::getRoot()
{
    return this->root;
}

//*******************************************************************
//delete the sub-tree rooted at 'node' and return number of nodes deleted
//This can be defined as a recursive function
int RedBlackTree::deleteNode(Node *node)
{
    int count = 0;
    if(node == NULL)
        return 0;
    else
    {
        //add your codes here
        count += this->deleteNode(node->leftChild);
        count += this->deleteNode(node->rightChild);
        delete(node);
        count++;
        return count;
        //----
    }
}

//****************************************************************
//This is the general BST insertion operation.
//It does not care about the color of the newly added node.
void RedBlackTree::insertNode(Node *node)
{
    if(node == NULL)
        return;
    if(this->root == NULL) // if the tree is empty
   {
        //add your codes here
       this->root = node;
        //----
    }
    else
   {
        //add your codes here
       string key = node->foodID + node->name + node->supplierID;
       Node* x = this->root;
       Node* y = x;
       
       while (x != NULL) {
           y = x;
           if (compareNodes(x, key) < 0) {
               x = x->rightChild;
           }
       }
       
       node->parent = y;
       
       if (compareNodes(y, key) < 0){
           y->leftChild = node;
       }else{
           y->rightChild = node;
       }
        //----
    }

    //At the end, need to call fixup() in case the newly
    //added node's parent is also RED
    fixUp(node);
}

//*******************************************************************
//At beginning, each newly added node will always be RED,
//this may violate the red-black tree property #4. fixUp()
//function will restore the property.
void RedBlackTree::fixUp(Node *z)
{
    if(z == root)
    {
        z->color = "BLACK";
        return;
     }

     //if z's color is 'RED' and its parent's color is also 'RED'
    while(z->color.compare("RED") == 0 &&
          z->parent != NULL &&
          z->parent->color.compare("RED") == 0)
    {
       //add your codes here
       //----
        if (z->parent->rightChild == z) {
            if (z->parent->parent->rightChild != NULL && z->parent->parent->rightChild->color.compare("RED") == 0) {
                z->parent->color = "BLACK";
                if (z->parent->parent != this->root) {
                    z->parent->parent->color = "RED";
                }
                z->parent->parent->rightChild->color = "BLACK";
                this->fixUp(z->parent->parent);
            }else{
                if (z->parent->rightChild == z) {
                    this->leftRotate(z->parent);
                    this->rightRotate(z->parent);
                    z->color = "BLACK";
                    z->rightChild->color = "RED";
                }else{
                    this->rightRotate(z->parent->parent);
                    z->parent->color = "BLACK";
                    z->parent->rightChild->color = "RED";
                    if (z->parent->rightChild->rightChild != NULL) {
                        this->fixUp(z->parent->rightChild->rightChild);
                    }
                }
            }
        }else{
            if (z->parent->parent->leftChild != NULL && z->parent->parent->leftChild->color.compare("RED") == 0) {
                z->parent->color = "BLACK";
                if (z->parent->parent != this->root) {
                    z->parent->parent->color = "RED";
                }
                z->parent->parent->leftChild->color = "BLACK";
                this->fixUp(z->parent->parent);
            }else{
                if (z->parent->leftChild == z) {
                    this->rightRotate(z->parent);
                    this->leftRotate(z->parent);
                    z->color = "BLACK";
                    z->leftChild->color = "RED";
                }else{
                    this->leftRotate(z->parent->parent);
                    z->parent->color = "BLACK";
                    z->parent->leftChild->color = "RED";
                    if (z->parent->leftChild->leftChild != NULL) {
                        this->fixUp(z->parent->leftChild->leftChild);
                    }
                }
            }
        }
       //----
    }//end while
    //make sure the root is always 'BLACK'
    this->root->color = "BLACK";
}

//*****************************************************
//This function print the pre-order traversal of the
//subtree rooted at 'node'.It's a recursive function
void RedBlackTree::preOrderTraversal(Node *node)
{
    if(node == NULL)
   {
        return;
    }
    else
   {
       //add your codes here
       //----
       this->print(node);
       this->preOrderTraversal(node->leftChild);
       this->preOrderTraversal(node->rightChild);
       //----
    }
}

//**************************************************
//This function print the in-order traversal of the
//subtree rooted at 'node'.It's a recursive function
void RedBlackTree::inorderTraversal(Node *node)
{
   if(node == NULL)
   {
        return;
    }
    else
   {
       //add your codes here
       //----
       this->inorderTraversal(node->leftChild);
       this->print(node);
       this->inorderTraversal(node->rightChild);
       //----
    }
}

//**************************************************
//This function print the post-order traversal of the
//subtree rooted at 'node'.It's a recursive function
void RedBlackTree::postOrderTraversal(Node *node)
{
   if(node == NULL)
   {
        return;
    }
    else
   {
       //add your codes here
       //----
       this->postOrderTraversal(node->leftChild);
       this->postOrderTraversal(node->rightChild);
       this->print(node);
       //----
    }
}

//**************************************************************
//This function returns a pointer points to the minimum node from
//the current sub-tree rooted at 'node'. It's a recursive function
Node* RedBlackTree::findMinimumNode(Node *node)
{
    if (node == NULL)
   {
        cout << "Tree is empty, no MINIMUM." << endl;
        return node;
    }
    else
    {
       //add your codes here
       //----
        while (node->leftChild != NULL) {
            node = node->leftChild;
        }
        return node;
       //----
     }
}

//**************************************************************
//This function returns a pointer points to the maximum node from
//the current sub-tree rooted at 'node'. It's a recursive function
Node* RedBlackTree::findMaximumNode(Node *node)
{
    if (node == NULL)
   {
        cout << "Tree is empty, no MAXIMUM." << endl;
        return node;
    }
   else
   {
       //add your codes here
       //----
       while (node->rightChild != NULL) {
           node = node->rightChild;
       }
       return node;
       //----
    }
}

//**************************************************************
//This function search the tree for a given key of a Food
//Note: key is the combination of foodID, name, supplierID
//It returns a pointer points to the node if founded, otherwise return NULL
Node* RedBlackTree::treeSearch(string foodID, string name, string supplierID)
{
   string key1 = foodID + name + supplierID;
    Node *node = root;
    bool found = false;
    while(node != NULL)
    {
        //----
        string key2 = node->foodID + node->name + node->supplierID;
        if(key1.compare(key2) == 0){
            found = true;
            break;
        }else if(this->compareNodes(node, key1) < 0){
            node = node->leftChild;
        }else{
            node = node->rightChild;
        }
    }
        //-----
        if(found)
        {
            cout << left;
            cout << setw(5) << foodID
            << setw(35) << name
            << setw(15) << supplierID
            << " is FOUND." << endl;
            return node;
        }
      else
      {
         cout << left;
         cout << setw(5) << foodID
              << setw(35) << name
              << setw(15) << supplierID
              << " is NOT FOUND." << endl;
         return NULL;
      }
//}

//****************************************************
//This function left-rotate the BST at 'node'
void RedBlackTree::leftRotate(Node *node)
{
    if(node == NULL){
        return;
    }else{
        Node* y = node->rightChild;
        node->rightChild = y->leftChild;
        if (y->leftChild != NULL) {
            y->leftChild->parent = node;
        }
        y->parent = node->parent;
        if (node->parent == NULL) {
            this->root = y;
        }else if(node == node->parent->leftChild){
            node->parent->leftChild = y;
        }else{
            node->parent->rightChild = y;
        }
        y->leftChild = node;
        node->parent = y;
    }

    //add your codes here
    //----
    
    //----
}

//***************************************************
//This function right-rotate the BST at 'node'
void RedBlackTree::rightRotate(Node *node)
{
    if(node == NULL){
        return;
    }else{
        Node* y = node->leftChild;
        node->leftChild = y->rightChild;
        if (y->rightChild != NULL) {
            y->rightChild->parent = node;
        }
        y->parent = node->parent;
        if (node->parent == NULL) {
            this->root = y;
        }else if(node == node->parent->leftChild){
            node->parent->leftChild = y;
        }else{
            node->parent->rightChild = y;
        }
        y->rightChild = node;
        node->parent = y;
    }

    //add your codes here
    //----
    //----
}


//**************************************************************
//This function finds the predecessor of the given 'node'
//it prints the relevant predecessor info. on screen.
Node* RedBlackTree::findPredecessorNode(Node *node)
{
   Node* predn;
    
    if (node->leftChild != NULL) {
        predn = this->findMaximumNode(node->leftChild);
    }else if(node->parent != NULL){
        predn = node->parent;
        while (predn != NULL && node == predn->leftChild) {
            node = predn;
            predn = predn->parent;
        }
    }
    
   if(predn != NULL)
   {
      //add your codes here
      //----
      cout << left;
      cout << "Its Predecessor is: " << endl;
      print(predn);
      return predn;
    }
    else  //not found
    {
       //add your codes here
      //----
      cout << left;
      cout << "Its Predecessor does NOT EXIST"    << endl;
      return predn;
    }
}

//**************************************************************
//This function finds the successor of the given 'node'
//it prints the relevant successor info. on screen.
Node* RedBlackTree::findSuccessorNode(Node *node)
{
   Node* sn;
    
    if (node->rightChild != NULL) {
        sn = this->findMinimumNode(node->rightChild);
    }else if(node->parent != NULL){
        sn = node->parent;
        while (sn != NULL && node == sn->rightChild) {
            node = sn;
            sn = sn->parent;
        }
    }
    
   if(sn != NULL)
   {
      //add your codes here
      //----
      cout << left;
      cout << "Its Successor is: " << endl;
        print(sn);
        return sn;
    }
    else  //not found
   {
      cout << left;
      cout << "Its Successor does NOT EXIST"    << endl;
      return sn;
    }
}

//**************************************************************
//This function find the minimum node of the entire red-black tree
//It print out the minimum node info. on screen if tree is not empty
//or print 'Tree is empty' message on screen.
void RedBlackTree::treeMinimum()
{
    if (root == NULL)
   {
        cout << "Tree is empty. No Minimum." << endl;
        return;
   }else{
       Node* min = this->findMinimumNode(this->root);
       cout << "The MINIMUM is:" << endl;
       this->print(min);
   }

    //add your codes here
    //----
    //----
}

//**************************************************************
//This function find the maximum node of the entire red-black tree
//It print out the maximum node info. on screen if tree is not empty
//or print 'Tree is empty' message on screen.
void RedBlackTree::treeMaximum()
{
    if (root == NULL)
    {
        cout << "Tree is empty. No Maximum." << endl;
        return;
    }else{
        Node* max = this->findMaximumNode(this->root);
        cout << "The MAXIMUM is:" << endl;
        this->print(max);
    }

    //add your codes here
    //----
    //----
}

//******************************************************************
//This function print out the pre-order traversal of the entire tree
void RedBlackTree::treePreorder()
{
    //add your codes here
    //----
    this->preOrderTraversal(this->root);
    //----
}

//******************************************************************
//This function print out the in-order traversal of the entire tree
void RedBlackTree::treeInorder()
{
    //add your codes here
    //----
    this->inorderTraversal(this->root);
    //----
}

//******************************************************************
//This function print out the post-order traversal of the entire tree
void RedBlackTree::treePostorder()
{
    //add your codes here
    //----
    this->postOrderTraversal(this->root);
    //----
}

//******************************************************************
//Given a Food's key, this function first check whether the
//food is inside the tree or not, if it is inside, it will print
//its predecessor info. on screen, if not, it print an error message
void RedBlackTree::treePredecessor(string foodID, string name, string supplierID)
{
    if (root == NULL)
        cout << "Tree is empty. No Predecessor." << endl;
    else
   {
      //add your codes here
      //----
       Node* node = this->treeSearch(foodID, name, supplierID);
       if (node != NULL) {
           this->findPredecessorNode(node);
       }
      //----
    }
}

//******************************************************************
//Given a food's key, this function first check whether the
//food is inside the tree or not, if it is inside, it will print
//its successor info. on screen, if not, it print an error message
void RedBlackTree::treeSucessor(string foodID, string name, string supplierID)
{
    if (root == NULL)
        cout << "Tree is empty. No Successor." << endl;
    else
   {
      //add your codes here
      //----
       Node* node = this->treeSearch(foodID, name, supplierID);
       if (node != NULL) {
           this->findSuccessorNode(node);
       }
      //----
    }
}

//**************************************************************
//This function create a node from the given info., then insert
//the node inside the red-black tree. Note: at beginning, the newly
//added node should always be 'RED'
void RedBlackTree::treeInsert(string foodID, string name, string supplierID, double price)
{
    //add your codes here
    //----
    Node* newNode = new Node;
    newNode->foodID = foodID;
    newNode->name = name;
    newNode->supplierID = supplierID;
    newNode->price = price;
    newNode->color = "RED";
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->parent = NULL;
    this->insertNode(newNode);

    //----
}

//******************************************************************
//Given a 'node', this function prints all its information on screen
void RedBlackTree::print(Node *node)
{
        cout << left;
        cout << setw(5) << node->foodID
             << setw(35) << node->name
             << setw(15) << node->supplierID
            << setw(7) << fixed << setprecision(2) << node->price
            << setw(7) << node->color << endl;
}

//**************************************************************
//Given a Node 'node1', this function compares it with another
//node's key.
//key is a string combination of foodID + name + supplierID
//It returns a negative number if in alphabetical order, key2 is
//in front of 'node1'; otherwise it returns a positive number
int RedBlackTree::compareNodes(Node *node1, string key2)
{
    //add your codes here
    //----
    string key1 = node1->foodID + node1->name + node1->supplierID;
    if (key1.compare(key2) < 0) {
        return 1;
    }else{
        return -1;
    }
    //----
}

