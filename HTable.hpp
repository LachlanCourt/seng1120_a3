/*************************************
**** Lachlan Court
**** c3308061
**** 13/11/2020
**** SENG1120 Assignment 3
**************************************/

#include <iostream>

// Default Constructor
template <typename value_type>
HTable<value_type>::HTable()
{

}

// Destructor
template <typename value_type>
HTable<value_type>::~HTable()
{
    // The hash table is stored on the stack and will be automatically deleted at the end of the program execution
}

// Adds an item into the hashtable using the hash function
template <typename value_type>
void HTable<value_type>::add(value_type item)
{
    data[hashfun(item)] = item;
}

// Removes an item from the hashtable using the hash function
template <typename value_type>
value_type HTable<value_type>::remove(value_type item)
{
    // Check that the item found using the hash function is the correct one to avoid removal collisions
    if (data[hashfun(item)].compare(item) == 0)
    {
        data[hashfun(item)] = value_type();
    }
    return item;
}

// Get the logical size of the hashfunction array by adding up how many cells are not filled with a default item
template <typename value_type>
const int HTable<value_type>::getSize() const
{
    // Initialise count at 0
    int count = 0;
    // Loop through the contents of the hashtable array
    for (int i = 0; i < 150; i++)
    {
        // If the item is not a default item, increment the count
        if (data[i].compare(value_type()) != 0)
        {
            count++;
        }
    }
    // Return the number of items in the hashtable
    return count;
}

/*
 * I think that this would lead to a memory leak and so I commented it out and replaced it with a string specific
 * function. This defeats the purpose of the template in this instance but I couldn't think of another way to do it
 */

// Returns only the valid contents of the hashtable array
/*
template <typename value_type>
value_type* HTable<value_type>::getContents()
{
    // Initialise an empty array to hold the contents
    static value_type contents[150];
    // Declare the logical size
    int size = 0;
    // Loop through every element of the hashtable array
    for (int i = 0; i < 150; i++)
    {
        // If the element is not a default item, add it to the contents array
        if (data[i].compare(value_type()) != 0)
        {
            contents[size] = data[i];
            // Increase the logical size of the array
            size++;
        }
    }
    // Return the pointer to the contents array
    return contents;
}*/

// Returns only the valid contents of the hashtable array
template <typename value_type>
string HTable<value_type>::getContents()
{
    // Initialise an empty string to hold the contents
    string contents = "";
    // Loop through every element of the hashtable array
    for (int i = 0; i < 150; i++)
    {
        // If the element is not a default item, add it to the contents array
        if (data[i].compare(value_type()) != 0)
        {
            contents += data[i] + " ";
        }
    }
    // Return the pointer to the contents array
    return contents;
}

/*
 * I think that this would lead to a memory leak and so I commented it out and replaced it with a string specific
 * function. This defeats the purpose of the template in this instance but I couldn't think of another way to do it
 */

// Overloaded += operator
/*
template <typename value_type>
void HTable<value_type>::operator+=(HTable hTable2)
{
    // Get a new array of the contents of the hashtable array
    value_type* contents = hTable2.getContents();
    // Loop through the logical size of the new array
    for (int i = 0; i < hTable2.getSize(); i++)
    {
        // For each item in the array, add it into the hashtable
        value_type temp = value_type(contents[i]);
        add(temp);
    }
    //if (contents != NULL)
    //{
    //    delete (contents);
    //}
}*/

// Overloaded += operator
template <typename value_type>
void HTable<value_type>::operator+=(HTable hTable2)
{
    // Get a new array of the contents of the hashtable array
    string contents = hTable2.getContents();
    // Declare a temp string which will hold the value of the string iterated so far
    string temp = "";
    // Loop through the parsed data one character at a time
    for (long unsigned int i = 0; i < contents.length(); i++)
    {
        // If the character is a space, the word will be added to the table
        if (contents[i] == ' ')
        {
            add(value_type(temp));
            // Reset temp ready for a new word
            temp = "";
        }
        else
        {
            // If the character is not a space, add the character to temp
            temp += contents[i];
        }
    }
}

// Hash Function
template <typename value_type>
const int HTable<value_type>::hashfun(value_type item)
{
    // Initialise result at 0
    int addResult = 0;
    // Loop through each character in the string
    for (long unsigned int i = 0; i < item.length(); i++)
    {
        // Add the ASCII code of that character to the result
        addResult += (int) item.at(i);
    }
    // Modulus divide the result by the number of positions in the array and return
    return addResult % 150;
}

// Public helper function to output the hashtable
template <typename value_type>
const string HTable<value_type>::outputHelper()
{
    // Initialise the string with a newline
    string returnData = " ";
    // Loop through each item in the array
    for (int i = 0; i < 150; i++)
    {
        // If the array is not a default item, add it to the returnData string with newline characters for formatting
        if (data[i].compare(value_type()) != 0)
        {
            returnData += data[i] + " ";
        }
    }
    // Return
    return returnData;
}

// Overloaded << operator
template <typename value_type>
ostream& operator<<(ostream& out, HTable<value_type> temp)
{
    // Call the public helper function of the hashtable
    out << temp.outputHelper();
    return out;
}

