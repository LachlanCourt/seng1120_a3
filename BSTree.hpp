/*************************************
**** Lachlan Court
**** c3308061
**** 13/11/2020
**** SENG1120 Assignment 3
**************************************/

//cd /cygdrive/C/Users/lachl/OneDrive/Documents/Uni/SENG1120_Assessment/Assignment3

#include <iostream>
#include <sstream>

// Default Constructor
template <typename value_type>
BSTree<value_type>::BSTree()
{
    root = NULL;
}

// Destructor
template <typename value_type>
BSTree<value_type>::~BSTree()
{
    while (root != NULL)
    {
        remove(root->getData());
    }
}

// Adds the argument item to the BST
template <typename value_type>
void BSTree<value_type>::add(value_type item)
{
    // If the root is NULL, create a new node and set the root variable to point to the new node
    if (root == NULL)
    {
        root = new BTNode<value_type>(item);
        return;
    }
    // If the root already exists, call the recursive helper function and pass it the root node to start
    addHelper(root, item);
}

// Determines the correct spot to add the item too
template <typename value_type>
void BSTree<value_type>::addHelper(BTNode<value_type>* testNode, value_type data_)
{
    // Determine if the item comes lexicographically before or after the current node being tested
    int nextNode = compareData(testNode->getData(), data_);
    
    // If it comes before
    if (nextNode == -1)
    {
        // If there is no left child currently, add a new left child with the specified data
        if (testNode->getLeft() == NULL)
        {
            testNode->setLeft(new BTNode<value_type>(data_, testNode, -1));
            testNode = NULL;
            return;
        }
        // If there already is a left child, call the helper function again on that left child
        else
        {
            addHelper(testNode->getLeft(), data_);
            testNode = NULL;
            return;
        }
    }
    // If it comes after
    else if (nextNode == 1)
    {
        // If there is no right child currently, add a new right child with the specified data
        if (testNode->getRight() == NULL)
        {
            testNode->setRight(new BTNode<value_type>(data_, testNode, 1));
            testNode = NULL;
            return;
        }
            // If there already is a right child, call the helper function again on that right child
        else
        {
            addHelper(testNode->getRight(), data_);
            testNode = NULL;
            return;
        }
    }
    // If the item is identical to an item already in the tree, simply return as the tree cannot contain duplicates
    else if (nextNode == 0)
    {
        testNode = NULL;
        return;
    }
}

// Determines which item comes lexicographically before the other, returns -1 if before, 0 if identical and 1 if after
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
    /*
     * If the for loop above has reached the length of the smallest word, a they are the same (Or the larger word starts
     * with the smaller word)
     */
    if (i == smallest)
    {
        return 0;
    }
    // Now that a unique character has been found, compare ASCII  to determine which comes first
    if ((int) nodeData[i] > (int) testData[i])
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

// Public helper function for the overloaded output operator
template <typename value_type>
const string BSTree<value_type>::outputHelper()
{
    // Calls the infix function on the root and returns the result
    return infix(root);
}

// Recursive inorder traversal to output the data in the tree
template <typename value_type>
const string BSTree<value_type>::infix(BTNode<value_type>* node)
{
    // Base case. If it has reached a leaf, return an empty string
    if (node == NULL)
    {
        return "";
    }
    /*
    * If the traversal has not reached a leaf, call infix on the left child, then add it's own data, then on the right
    * child and return the result
    */
    else
    {
        return infix(node->getLeft()) + node->getData() + " " + infix(node->getRight());
    }
}

// Removes the specified item from the BST
template <typename value_type>
value_type BSTree<value_type>::remove(value_type item)
{
    // Find where the item is in the tree
    BTNode<value_type>* tempNode = findItem(root, item);
    // If findItem returns NULL, that means that the item does not exist in the tree
    if (tempNode == NULL)
    {
        return value_type();
    }
    
    // Case 1 when the item to be removed is the root node
    if (tempNode == root)
    {
        // Check if the root node has a right child
        if (root->getRight() != NULL)
        {
            // Use the findReplacement helper function to traverse to the left most node of the root node's right child
            BTNode<value_type>* replacementNode = findReplacement(root->getRight());
            // Recursively call remove on the replacement node
            value_type tempData = remove(replacementNode->getData());
            // Set the data of the root node to that of the replacement node
            root->setData(tempData);
            // Return the data
            return tempData;
        }
        // Check if the root node has a left child (Therefore mustn't have a right child
        else if (root->getLeft() != NULL)
        {
            // Save the old root node
            BTNode<value_type>* oldRoot = root;
            // Set the root node to the left child
            root = root->getLeft();
            // Reset the new root
            root->setParent(NULL);
            root->setSide(0);
            // Grab the data of the old root, and delete the node
            value_type tempData = oldRoot->getData();
            delete (oldRoot);
            // Return the data
            return tempData;
        }
        // The root node has no children
        else
        {
            // Save the data of the root node
            value_type tempData = root->getData();
            // Delete the root node and set it to NULL
            delete (root);
            root = NULL;
            // Return the data
            return tempData;
        }
    }
    
    // Case 2 when the item to be removed is a leaf node
    if ((tempNode->getLeft() == NULL) && (tempNode->getRight() == NULL))
    {
        // If the node being removed is a left child
        if (tempNode->getSide() == -1)
        {
            // Set the parent's left child pointer to NULL
            tempNode->getParent()->setLeft(NULL);
        }
        // If the node being removed is a right child
        else if (tempNode->getSide() == 1)
        {
            // Set the parent's right child pointer to NULL
            tempNode->getParent()->setRight(NULL);
        }
        // Save the data from the node
        value_type tempData = tempNode->getData();
        // Delete the node
        delete (tempNode);
        // Return the data
        return tempData;
    }
    
    // Item must be an internal node
    // Case 3 when the item to be removed has 1 child
    if (((tempNode->getLeft() == NULL) && (tempNode->getRight() != NULL)) ||
        ((tempNode->getRight() == NULL) && (tempNode->getLeft() != NULL)))
    {
        // If the node being removed is a left child
        if (tempNode->getSide() == -1)
        {
            // If the node's child is on the left
            if (tempNode->getLeft() != NULL)
            {
                // Link the nodes left child to the node's parent
                tempNode->getLeft()->setParent(tempNode->getParent());
                tempNode->getParent()->setLeft(tempNode->getLeft());
            }
            // If the node's child is on the right
            if (tempNode->getRight() != NULL)
            {
                // Link the nodes right child to the node's parent
                tempNode->getRight()->setParent(tempNode->getParent());
                tempNode->getParent()->setLeft(tempNode->getRight());
                tempNode->getRight()->setSide(-1);
            }
        }
        // If the node being removed is a right child
        if (tempNode->getSide() == 1)
        {
            // If the node's child is on the left
            if (tempNode->getLeft() != NULL)
            {
                // Link the nodes left child to the node's parent
                tempNode->getLeft()->setParent(tempNode->getParent());
                tempNode->getParent()->setRight(tempNode->getLeft());
                tempNode->getLeft()->setSide(1);
            }
            // If the node's child is on the right
            if (tempNode->getRight() != NULL)
            {
                // Link the nodes right child to the node's parent
                tempNode->getRight()->setParent(tempNode->getParent());
                tempNode->getParent()->setRight(tempNode->getRight());
            }
        }
        // Save the data from the node
        value_type tempData = tempNode->getData();
        // Delete the node
        delete (tempNode);
        // Return the data
        return tempData;
    }
    
    // Case 4 when the item to be removed has 2 children
    // Use the findReplacement helper function to traverse to the left most node of the current node's right child
    BTNode<value_type>* replacementNode = findReplacement(tempNode->getRight());
    // Recursively call remove on the replacement node
    value_type tempData = remove(replacementNode->getData());
    // Set the data of the current node to that of the replacement node
    tempNode->setData(tempData);
    // Return the data
    return tempData;
    
    // **** I done messed up here on my first remove function but I like being able to look back ****//
    
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

// Recursive helper function for remove function to find the best node to replace the one being removed
template <typename value_type>
BTNode<value_type>* BSTree<value_type>::findReplacement(BTNode<value_type>* testNode)
{
    // If the left child exists, call findReplacement again on the left child
    if (testNode->getLeft() != NULL)
    {
        return findReplacement(testNode->getLeft());
    }
        // Otherwise return the current node as the base case
    else
    {
        return testNode;
    }
    
}

// Recursive helper function for the remove function to find the node that contains the specified data
template <typename value_type>
BTNode<value_type>* BSTree<value_type>::findItem(BTNode<value_type>* testNode, value_type item)
{
    // If the node being tested is NULL, the item does not exist in the tree
    if (testNode == NULL)
    {
        return NULL;
    }
    // If the item is to the left of the current node, call findItem on the left child
    if (compareData(testNode->getData(), item) == -1)
    {
        return findItem(testNode->getLeft(), item);
    }
        // If the item is to the right of the current node, call findItem on the right child
    else if (compareData(testNode->getData(), item) == 1)
    {
        return findItem(testNode->getRight(), item);
    }
        // If the item matches the data in the current node, return that node back up the chain
    else if (compareData(testNode->getData(), item) == 0)
    {
        return testNode;
    }
    // Control should not reach here but should always return from a non-void function
    return NULL;
}

// Returns the data in the root node
template <typename value_type>
const value_type BSTree<value_type>::getRoot()
{
    // If the root node is NULL the tree is empty. Return a default item
    if (root == NULL)
    {
        return value_type();
    }
    // If the root node is not null, return the data stored in it
    return root->getData();
}

// Overloaded += operator
template <typename value_type>
void BSTree<value_type>::operator+=(BSTree<value_type>& tree2)
{
    // While the root node of the right hand tree is not empty
    while (tree2.getRoot().compare(value_type()) != 0)
    {
        // Get the data from the root node
        value_type temp = tree2.getRoot();
        // Add it to the left hand tree
        add(temp);
        // Remove the root node of the right hand tree so that a new node takes its place
        tree2.remove(tree2.getRoot());
    }
}

// Overloaded << operator
template <typename value_type>
ostream& operator<<(ostream& out, BSTree<value_type>& temp)
{
    
    // Output the return from the helper function
    out << temp.outputHelper();
    return out;
}