//cd /cygdrive/C/Users/lachl/OneDrive/Documents/Uni/SENG1120_Assessment/Assignment3
#include <iostream>
#include <sstream>

template <typename value_type>
BSTree<value_type>::BSTree()
{
    root = NULL;
}

template <typename value_type>
BSTree<value_type>::~BSTree()
{
    while (root != NULL)
    {
        remove(root->getData());
    }
}

template <typename value_type>
void BSTree<value_type>::add(value_type item)
{
    if (root == NULL)
    {
        root = new BTNode<value_type>(item);
        return;
    }
    addHelper(root, item);
}

template <typename value_type>
void BSTree<value_type>::addHelper(BTNode<value_type>* testNode, value_type data_)
{
    int nextNode = compareData(testNode->getData(), data_);
    
    if (nextNode == -1)
    {
        if (testNode->getLeft() == NULL)
        {
            testNode->setLeft(new BTNode<value_type>(data_, testNode, -1));
            return;
        }
        else
        {
            addHelper(testNode->getLeft(), data_);
            return;
        }
    }
    else if (nextNode == 1)
    {
        if (testNode->getRight() == NULL)
        {
            testNode->setRight(new BTNode<value_type>(data_, testNode, 1));
            return;
        }
        else
        {
            addHelper(testNode->getRight(), data_);
            return;
        }
    }
    else if (nextNode == 0)
    {
        testNode = NULL;
        return;
    }
}

template <typename value_type>
const int BSTree<value_type>::compareData(string nodeData, string testData)
{
    // Determine which of the two words is shorter
    int smallest = (int) nodeData.length();
    if ((int) testData.length() < smallest)
    {
        smallest = testData.length();
    }
    
    // Loop through the length of the smaller word
    int i;
    for (i = 0; i < smallest; i++)
    {
        // Keep checking until a character that is unique in the two words is found
        if ((int) nodeData[i] != (int) testData[i])
        {
            break;
        }
    }
    // If the for loop above has reached the length of the smallest word, a swap is not necessary as they are the same (Or the larger word starts with the smaller word)
    if (i == smallest)
    {
        return 0;
    }
    // Now that a unique character has been found, determine if a swap is necessary by comparing ASCII codes
    if ((int) nodeData[i] > (int) testData[i])
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

template <typename value_type>
const string BSTree<value_type>::outputHelper()
{
    return infix(root);
}

template <typename value_type>
const string BSTree<value_type>::infix(BTNode<value_type>* node)
{
    if (node == NULL)
    {
        return "";
    }
    else if (node->getData().compare(value_type()) == 0)
    {
        return "";
    }
    else
    {
        return infix(node->getLeft()) + "\n" + node->getData() + "\n" + infix(node->getRight());
    }
}

template <typename value_type>
value_type BSTree<value_type>::remove(value_type item)
{
    // Find where the item is in the tree
    BTNode<value_type>* tempNode = findItem(root, item);
    if (tempNode == NULL)
    {
        return value_type();
    }
    
    if (tempNode == root)
    {
        if (root->getRight() != NULL)
        {
            BTNode<value_type>* replacementNode = findReplacement(root->getRight());
            value_type tempData = remove(replacementNode->getData());
            root->setData(tempData);
            return tempData;
        }
        else if (root->getLeft() != NULL)
        {
            BTNode<value_type>* oldRoot = root;
            root = root->getLeft();
            root->setParent(NULL);
            root->setSide(0);
            value_type tempData = oldRoot->getData();
            delete (oldRoot);
            return tempData;
        }
        else
        {
            value_type tempData = root->getData();
            delete (root);
            root = NULL;
            return tempData;
        }
    }
    
    // Check if item is a leaf node
    if ((tempNode->getLeft() == NULL) && (tempNode->getRight() == NULL))
    {
        if (tempNode->getSide() == -1)
        {
            tempNode->getParent()->setLeft(NULL);
        }
        else if (tempNode->getSide() == 1)
        {
            tempNode->getParent()->setRight(NULL);
        }
        value_type tempData = tempNode->getData();
        delete (tempNode);
        return tempData;
    }
    
    // Item must be an internal node
    // Check if it has one child
    if (((tempNode->getLeft() == NULL) && (tempNode->getRight() != NULL)) ||
        ((tempNode->getRight() == NULL) && (tempNode->getLeft() != NULL)))
    {
        if (tempNode->getSide() == -1)
        {
            if (tempNode->getLeft() != NULL)
            {
                tempNode->getLeft()->setParent(tempNode->getParent());
                tempNode->getParent()->setLeft(tempNode->getLeft());
            }
            if (tempNode->getRight() != NULL)
            {
                tempNode->getRight()->setParent(tempNode->getParent());
                tempNode->getParent()->setLeft(tempNode->getRight());
                tempNode->getRight()->setSide(-1);
            }
        }
        if (tempNode->getSide() == 1)
        {
            if (tempNode->getLeft() != NULL)
            {
                tempNode->getLeft()->setParent(tempNode->getParent());
                tempNode->getParent()->setRight(tempNode->getLeft());
                tempNode->getLeft()->setSide(1);
            }
            if (tempNode->getRight() != NULL)
            {
                tempNode->getRight()->setParent(tempNode->getParent());
                tempNode->getParent()->setRight(tempNode->getRight());
            }
        }
        value_type tempData = tempNode->getData();
        delete (tempNode);
        return tempData;
    }
    
    // Has two children
    BTNode<value_type>* replacementNode = findReplacement(tempNode->getRight());
    value_type tempData = remove(replacementNode->getData());
    tempNode->setData(tempData);
    return tempData;
    //return value_type();
    /*
    if (tempNode->getSide() == 1)
    {
        // If the node being removed is on the right hand side of its parent
        // If the node being removed has no right child
        if (tempNode->getRight() == NULL)
        {
            if (tempNode->getLeft() != NULL)
            {
                // Set the deleted item's left child's parent to the deleted item's parent
                tempNode->getLeft()->setParent(tempNode->getParent());
                // Set the deleted item's parent's right child to the deleted items left child
                tempNode->getParent()->setRight(tempNode->getLeft());
                // The node that was just moved will now be on a different side
                tempNode->getLeft()->setSide(1);
                // Pull out the data and delete the old node
                value_type tempData = tempNode->getData();
                delete (tempNode);
                // Return data
                return tempData;
            }
            else
            {
                tempNode->getParent()->setRight(NULL);
                value_type tempData = tempNode->getData();
                delete (tempNode);
                return tempData;
            }
        }
        
        else
        {
            BTNode<value_type>* smallestNode = tempNode->getRight();
            while (smallestNode->getLeft() != NULL)
            {
                smallestNode = smallestNode->getLeft();
            }
            cout << smallestNode->getData();
            
            if (smallestNode->getRight() != NULL)
            {
                smallestNode->getRight()->setParent(smallestNode->getParent());
                smallestNode->getParent()->setLeft(smallestNode->getRight());
                smallestNode->getRight()->setSide(-1);
            }
            
            tempNode->getParent()->setRight(smallestNode);
            smallestNode->setParent(tempNode->getParent());
            smallestNode->setSide(1);
            
            smallestNode->setLeft(tempNode->getLeft());
            if (smallestNode->getLeft() != NULL)
            {
                smallestNode->getLeft()->setParent(smallestNode);
            }
            
            if (tempNode->getRight() != smallestNode)
            {
                smallestNode->setRight(tempNode->getRight());
                if (smallestNode->getRight() != NULL)
                {
                    //smallestNode->getRight()->setParent(smallestNode);
                }
            }
            
        }
    }
    else if (tempNode->getSide() == -1)
    {
        if (tempNode->getRight() == NULL)
        {
            if (tempNode->getLeft() != NULL)
            {
                tempNode->getLeft()->setParent(tempNode->getParent());
                tempNode->getParent()->setLeft(tempNode->getLeft());
                value_type tempData = tempNode->getData();
                delete (tempNode);
                return tempData;
            }
            else
            {
                tempNode->getParent()->setLeft(NULL);
                value_type tempData = tempNode->getData();
                delete (tempNode);
                return tempData;
            }
        }
        else
        {
            BTNode<value_type>* smallestNode = tempNode->getRight();
            while (smallestNode->getLeft() != NULL)
            {
                smallestNode = smallestNode->getLeft();
            }
            
            if (smallestNode->getRight() != NULL)
            {
                smallestNode->getRight()->setParent(smallestNode->getParent());
                smallestNode->getParent()->setLeft(smallestNode->getRight());
                smallestNode->getRight()->setSide(-1);
            }
    
            tempNode->getParent()->setLeft(smallestNode);
            smallestNode->setParent(tempNode->getParent());
            smallestNode->setSide(-1);
    
            smallestNode->setLeft(tempNode->getLeft());
            if (smallestNode->getLeft() != NULL)
            {
                smallestNode->getLeft()->setParent(smallestNode);
            }
            if (tempNode->getRight() != smallestNode)
            {
                smallestNode->setRight(tempNode->getRight());
                if (smallestNode->getRight() != NULL)
                {
                    smallestNode->getRight()->setParent(smallestNode);
                }
            }
    
            value_type tempData = tempNode->getData();
            delete (tempNode);
            return tempData;
            
        }
    }
    */
}

template <typename value_type>
BTNode<value_type>* BSTree<value_type>::findReplacement(BTNode<value_type>* testNode)
{
    if (testNode->getLeft() != NULL)
    {
        return findReplacement(testNode->getLeft());
    }
    else
    {
        return testNode;
    }
    
}

template <typename value_type>
BTNode<value_type>* BSTree<value_type>::findItem(BTNode<value_type>* testNode, value_type item)
{
    if (testNode == NULL)
    {
        return NULL;
    }
    if (compareData(testNode->getData(), item) == -1)
    {
        return findItem(testNode->getLeft(), item);
    }
    else if (compareData(testNode->getData(), item) == 1)
    {
        return findItem(testNode->getRight(), item);
    }
    else if (compareData(testNode->getData(), item) == 0)
    {
        return testNode;
    }
    return NULL;
}

template <typename value_type>
const value_type BSTree<value_type>::getRoot()
{
    if (root == NULL)
    {
        return value_type();
    }
    return root->getData();
}

template <typename value_type>
void BSTree<value_type>::operator+=(BSTree<value_type>& tree2)
{
    while (tree2.getRoot().compare(value_type()) != 0)
    {
        value_type temp = tree2.getRoot();
        add(temp);
        tree2.remove(tree2.getRoot());
    }
}

template <typename value_type>
ostream& operator<<(ostream& out, BSTree<value_type>& temp)
{
    out << temp.outputHelper();
    return out;
}