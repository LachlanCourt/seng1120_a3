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
        BSTree();
        
        ~BSTree();
        
        void add(const value_type item);
        
        value_type remove(const value_type item);
        
        void operator+=(BSTree<value_type>& tree2);
        
        const string outputHelper();
        
        const value_type getRoot();
    
    private:
        BTNode<value_type>* root;
        
        void addHelper(BTNode<value_type>* testNode, const value_type check);
        
        const int compareData(const string nodeData, const string testData);
        
        const string infix(BTNode<value_type>* node);
        
        BTNode<value_type>* findItem(BTNode<value_type>* testNode, const value_type item);
        
        BTNode<value_type>* findReplacement(BTNode<value_type>* testNode);
};

template <typename value_type>
ostream& operator<<(ostream& out, BSTree<value_type>& temp);

#include "BSTree.hpp"

#endif
