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
        
        value_type remove();
        
        void operator+=(const BSTree<value_type>& tree2);
    
    private:
};

template <typename value_type>
ostream& operator<<(ostream& out, BSTree<value_type> temp);

#include "BSTree.hpp"

#endif
