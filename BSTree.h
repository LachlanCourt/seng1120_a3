/*************************************
**** Lachlan Court
**** c3308061
**** 13/11/2020
**** SENG1120 Assignment 3
**************************************/

#include <iostream>

using namespace std;

#ifndef BSTree_Class
#define BSTree_Class

#include "BTNode.h"

template <typename value_type>
class BSTree
{
    public:
        // Constructor
        BSTree();
        
        // Destructor
        ~BSTree();
        
        // Precondition: None
        // Postcondition: The item is added to the BST
        void add(const value_type item);
        // Precondition: None
        // Postcondition: The specified item is removed from the BST
        value_type remove(const value_type item);
        // Precondition: None
        // Postcondition: Right hand side BST data is added to left hand side BST
        void operator+=(BSTree<value_type>& tree2);
        // Precondition: None
        // Postcondition: The contents of the BST is returned as a formatted String
        const string outputHelper();
        // Precondition: None
        // Postcondition: The data of the root node is returned, or a default object if the root node is NULL
        const value_type getRoot();
    
    private:
        // Instance variable
        BTNode<value_type>* root;
        
        // Precondition: None
        // Postcondition: testNode cannot be NULL
        void addHelper(BTNode<value_type>* testNode, const value_type check);
        // Precondition: None
        // Postcondition: Returns -1, 0, or 1 if the testData is lexicographically before, the same or after nodeData
        const int compareData(const string nodeData, const string testData);
        // Precondition: None
        // Postcondition: Returns the inorder traversal of the BST as a string to be printed out
        const string infix(BTNode<value_type>* node);
        // Precondition: None
        // Postcondition: The node that conains the specifed data is returned
        BTNode<value_type>* findItem(BTNode<value_type>* testNode, const value_type item);
        // Precondition: testNode cannot be NULL
        // Postcondition: The best replacement Node for the testNode provided is returned
        BTNode<value_type>* findReplacement(BTNode<value_type>* testNode);
};

// Precondition: None
// Postcondition: Calls the outputHelper function and outputs the result
template <typename value_type>
ostream& operator<<(ostream& out, BSTree<value_type>& temp);

#include "BSTree.hpp"

#endif
