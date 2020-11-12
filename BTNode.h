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
        void setData(const value_type data_);
        void setParent(BTNode<value_type>* parent_);
        void setLeft(BTNode<value_type>* left_);
        void setRight(BTNode<value_type>* right_);
        void setSide(const int side_);
        // Query
        value_type getData() const;
        BTNode<value_type>* getParent() const;
        BTNode<value_type>* getRight() const;
        BTNode<value_type>* getLeft() const;
        const int getSide() const;

    private:
        value_type data;
        int side;
        BTNode* left;
        BTNode* right;
        BTNode* parent;
};
#include "BTNode.hpp"
#endif
