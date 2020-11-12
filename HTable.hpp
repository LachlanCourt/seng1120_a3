#include <iostream>

template <typename value_type>
HTable<value_type>::HTable()
{

}

template <typename value_type>
HTable<value_type>::~HTable()
{

}

template <typename value_type>
void HTable<value_type>::add(value_type item)
{
    data[hashfun(item)] = item;
}

template <typename value_type>
value_type HTable<value_type>::remove(value_type item)
{
    if (data[hashfun(item)].compare(item) == 0)
    {
        data[hashfun(item)] = value_type();
    }
    return item;
}

template <typename value_type>
int HTable<value_type>::getSize()
{
    int count = 0;
    for (int i = 0; i < 150; i++)
    {
        if (data[i].compare(value_type()) != 0)
        {
            count++;
        }
    }
    return count;
}

template <typename value_type>
value_type* HTable<value_type>::getContents()
{
    static value_type contents[150];
    int size = 0;
    for (int i = 0; i < 150; i++)
    {
        if (data[i].compare(value_type()) != 0)
        {
            contents[size] = data[i];
            size++;
        }
    }
    return contents;
}

template <typename value_type>
void HTable<value_type>::operator+=(HTable hTable2)
{
    value_type* contents = hTable2.getContents();
    for (int i = 0; i < hTable2.getSize(); i++)
    {
        add(contents[i]);
    }
}

template <typename value_type>
int HTable<value_type>::hashfun(value_type item)
{
    int addResult = 0;
    for (long unsigned int i = 0; i < item.length(); i++)
    {
        addResult += (int) item.at(i);
    }
    // put you code here to add up the ASCII codes of all
    // characters in the parameter value and store in the
    // integer variable addResult
    return addResult % 150;
    
}

template <typename value_type>
string HTable<value_type>::outputHelper()
{
    string returnData = "\n";
    for (int i = 0; i < 150; i++)
    {
        if (data[i].compare(value_type()) != 0)
        {
            returnData += "\n" + data[i] + "\n";
        }
    }
    return returnData;
}

template <typename value_type>
ostream& operator<<(ostream& out, HTable<value_type> temp)
{
    out << temp.outputHelper();
    return out;
}

