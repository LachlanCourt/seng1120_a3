/*************************************
**** Lachlan Court
**** c3308061
**** 13/11/2020
**** SENG1120 Assignment 3
**************************************/

#include <iostream>

// Default Contructor
template <typename value_type>
BTNode<value_type>::BTNode()
{
    parent = NULL;
    left = NULL;
    right = NULL;
    side = 0;
}

// Constructors
template <typename value_type>
BTNode<value_type>::BTNode(value_type data_, BTNode* parent_, BTNode* left_, BTNode* right_)
{
    data = data_;
    parent = parent_;
    left = left_;
    right = right_;
    side = 0;
}

template <typename value_type>
BTNode<value_type>::BTNode(value_type data_, BTNode* parent_, int side_)
{
    data = data_;
    parent = parent_;
    side = side_;
    left = NULL;
    right = NULL;
}

template <typename value_type>
BTNode<value_type>::BTNode(value_type data_)
{
    data = data_;
    parent = NULL;
    left = NULL;
    right = NULL;
    side = 0;
}

// Destructor
template <typename value_type>
BTNode<value_type>::~BTNode()
{
    /*
     * The data for the node is stored locally on the stack and so it will be automatically be deleted when the node is
     * deleted
     */
}

// Sets the data variable to the value of the argument
template <typename value_type>
void BTNode<value_type>::setData(value_type data_)
{
    data = data_;
}

// Sets the parent node to the value in the argument
template <typename value_type>
void BTNode<value_type>::setParent(BTNode<value_type>* parent_)
{
    parent = parent_;
}

// Sets the left node to the value in the argument
template <typename value_type>
void BTNode<value_type>::setLeft(BTNode<value_type>* left_)
{
    left = left_;
}

// Sets the right node to the value in the argument
template <typename value_type>
void BTNode<value_type>::setRight(BTNode<value_type>* right_)
{
    right = right_;
}

// Sets the side to the value in the argument
template <typename value_type>
void BTNode<value_type>::setSide(int side_)
{
    side = side_;
}

// Returns the data of the node
template <typename value_type>
value_type BTNode<value_type>::getData() const
{
    return data;
}

// Returns the parent of the node
template <typename value_type>
BTNode<value_type>* BTNode<value_type>::getParent() const
{
    return parent;
}

// Returns the right child of the node
template <typename value_type>
BTNode<value_type>* BTNode<value_type>::getRight() const
{
    return right;
}

// Returns the left child of the node
template <typename value_type>
BTNode<value_type>* BTNode<value_type>::getLeft() const
{
    return left;
}

// Returns the which side of the parent the node is on
template <typename value_type>
const int BTNode<value_type>::getSide() const
{
    return side;
}


