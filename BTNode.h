#include <iostream>
using namespace std;
#ifndef BTNode_Class
#define BTNode_Class

template <typename value_type>
class BTNode
        Class BTNode (I)
class BTNode
{
    public:
        // Constructors
        BTNode();
        BTNode(value_type data, BTNode* parent, BTNode* left, BTNode* right);
        // Destructor
        ~BTNode();
        // Mutators
        void setData(const value_type);
        void setParent(BTNode*);
        void setLeft(BTNode*);
        void setRight(BTNode*);
        // Query
        value_type getData() const;
        BTNode* getParent();
        BTNode* getRight();
        BTNode* getLeft();

    private:
        value_type data;
        BTNode* left;
        BTNode* right;
        BTNode* parent;
};
#include "BTNode.hpp"
#endif
