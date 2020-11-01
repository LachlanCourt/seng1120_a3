#include <iostream>
using namespace std;

#ifndef BSTree_Class
#define BSTree_Class

template <typename value_type>
class BSTree
{
    BSTree();
    ~BSTree();

    void add(value_type);
    value_type remove();

    void operator += (const BSTree& tree2);

};

ostream& operator << (ostream& out, BSTree temp);

#endif
