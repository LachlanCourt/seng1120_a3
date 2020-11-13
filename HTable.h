/*************************************
**** Lachlan Court
**** c3308061
**** 13/11/2020
**** SENG1120 Assignment 3
**************************************/

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
        
        void add(const value_type item);
        
        value_type remove(const value_type item);
        
        void operator += (const HTable hTable2);
        
        const string outputHelper();
        
        const int getSize() const;
        
        value_type* getContents();
    
    private:
        const int hashfun(value_type item);
        
        value_type data[150];
};

template <typename value_type>
ostream& operator <<(ostream& out, HTable<value_type> temp);

#include "HTable.hpp"

#endif
