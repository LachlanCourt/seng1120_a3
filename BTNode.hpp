#include <iostream>

template <typename value_type>
BTNode<value_type>::BTNode()
{
    parent = NULL;
    left = NULL;
    right = NULL;
    side = 0;
}

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
// Mutators
template <typename value_type>
void BTNode<value_type>::setData(const value_type data_)
{
    data = data_;
}

template <typename value_type>
void BTNode<value_type>::setParent(BTNode<value_type>* parent_)
{
    parent = parent_;
}

template <typename value_type>
void BTNode<value_type>::setLeft(BTNode<value_type>* left_)
{
    left = left_;
}

template <typename value_type>
void BTNode<value_type>::setRight(BTNode<value_type>* right_)
{
    right = right_;
}

template <typename value_type>
void BTNode<value_type>::setSide(int side_)
{
    side = side_;
}

template <typename value_type>
value_type BTNode<value_type>::getData() const
{
    return data;
}

template <typename value_type>
BTNode<value_type>* BTNode<value_type>::getParent()
{
    return parent;
}

template <typename value_type>
BTNode<value_type>* BTNode<value_type>::getRight()
{
    return right;
}

template <typename value_type>
BTNode<value_type>* BTNode<value_type>::getLeft()
{
    return left;
}

template <typename value_type>
const int BTNode<value_type>::getSide() const
{
    return side;
}


