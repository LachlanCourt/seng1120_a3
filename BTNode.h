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
        BTNode(value_type data_, BTNode* parent_, BTNode* left_, BTNode* right_);
        BTNode(value_type data_);
        // Destructor
        ~BTNode();
        // Mutators
        void setData(const value_type data_);
        void setParent(BTNode<value_type>* parent_);
        void setLeft(BTNode<value_type>* left_);
        void setRight(BTNode<value_type>* right_);
        // Query
        value_type getData() const;
        BTNode<value_type>* getParent();
        BTNode<value_type>* getRight();
        BTNode<value_type>* getLeft();

    private:
        value_type data;
        BTNode* left;
        BTNode* right;
        BTNode* parent;
};
#include "BTNode.hpp"
#endif
