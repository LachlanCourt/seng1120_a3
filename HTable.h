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
        // Constructor
        HTable();
        
        // Destructor
        ~HTable();
        
        // Precondition: None
        // Postcondition: The item is added into the hashtable
        void add(const value_type item);
        // Precondition: None
        // Postcondition: If the item is in the hashtable it is returned
        value_type remove(const value_type item);
        // Precondition: None
        // Postcondition: Right hand side hashtable data is added to left hand side hashtable
        void operator += (const HTable hTable2);
        // Precondition: Hashtable should not be empty, but can be (no warning given)
        // Postcondition: Hasthtable data is printed out one line per item
        const string outputHelper();
        // Precondition: None
        // Postcondition: Returns the number of valid data items in the hashtable
        const int getSize() const;
        // Precondition: Return value must be iterated through using getSize in order to ensure all data is accessed
        // Postcondition: Returns an array containing all valid data items in the hashtable at the beginning
        value_type* getContents();
    
    private:
        // Precondition: None
        // Postcondition: Returns the hash function array index for the item given
        const int hashfun(value_type item);
        
        // Instance variable
        value_type data[150];
};

// Precondition: None
// Postcondition: Outputs the contents of the hashtable by calling the outputHelper function
template <typename value_type>
ostream& operator <<(ostream& out, HTable<value_type> temp);

#include "HTable.hpp"

#endif
