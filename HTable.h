#include <iostream>

using namespace std;

#ifndef HTable_Class
#define HTable_Class

template <typename value_type>
class HTable
{
    public:
        HTable();
        
        ~HTable();
        
        void add(value_type item);
        
        value_type remove(value_type item);
        
        void operator += (HTable hTable2);
        
        string outputHelper();
        
        int getSize();
        
        value_type* getContents();
    
    private:
        int hashfun(value_type item);
        
        value_type data[150];
};

template <typename value_type>
ostream& operator <<(ostream& out, HTable<value_type> temp);

#include "HTable.hpp"

#endif
