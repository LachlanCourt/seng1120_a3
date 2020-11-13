/*************************************
**** Lachlan Court
**** c3308061
**** 13/11/2020
**** SENG1120 Assignment 3
**************************************/

#include <iostream>
using namespace std;
#ifndef BTNode_Class
#define BTNode_Class

template <typename value_type>
class BTNode
{
    public:
        // Constructors
        BTNode();
        BTNode(const value_type data_, BTNode* parent_, BTNode* left_, BTNode* right_);
        BTNode(const value_type data_, BTNode* parent_, const int side_);
        BTNode(const value_type data_);
        
        // Destructor
        ~BTNode();
        
        // Mutators
        // Precondition: None
        // Postcondition: The data variable is set to the value of the argument
        void setData(const value_type data_);
        // Precondition: None
        // Postcondition: The parent variable is set to the value of the argument
        void setParent(BTNode<value_type>* parent_);
        // Precondition: None
        // Postcondition: The left variable is set to the value of the argument
        void setLeft(BTNode<value_type>* left_);
        // Precondition: None
        // Postcondition: The right variable is set to the value of the argument
        void setRight(BTNode<value_type>* right_);
        // Precondition: None
        // Postcondition: The side variable is set to the value of the argument
        void setSide(const int side_);
        // Queries
        // Precondition: None
        // Postcondition: The data in the node is returned
        value_type getData() const;
        // Precondition: None
        // Postcondition: The parent node is returned
        BTNode<value_type>* getParent() const;
        // Precondition: None
        // Postcondition: The right child node is returned
        BTNode<value_type>* getRight() const;
        // Precondition: None
        // Postcondition: The left child node is returned
        BTNode<value_type>* getLeft() const;
        // Precondition: None
        // Postcondition:  The side value recording if the node is a left child or a right child is returned
        const int getSide() const;

    private:
        // Instance variables
        value_type data;
        int side;
        BTNode* left;
        BTNode* right;
        BTNode* parent;
};
#include "BTNode.hpp"
#endif
