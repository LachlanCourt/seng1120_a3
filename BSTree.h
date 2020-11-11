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
        
        void add(value_type);
        
        value_type remove(value_type item);
        
        void operator+=(const BSTree<value_type>& tree2);
        
        string outputHelper();
    
    private:
        BTNode<value_type>* root;
        
        void addHelper(BTNode<value_type>* testNode, value_type check);
        
        int compareData(string nodeData, string testData);
        
        string infix(BTNode<value_type>* node);
        
        BTNode<value_type>* findItem(BTNode<value_type>* testNode, value_type item);
        
        BTNode<value_type>* findReplacement(BTNode<value_type>* testNode);
};

template <typename value_type>
ostream& operator<<(ostream& out, BSTree<value_type> temp);

#include "BSTree.hpp"

#endif
