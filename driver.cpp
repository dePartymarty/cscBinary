#include <stdlib.h>
#include <iostream>

using namespace std;

// did a struct because it seemed easier for this problem
struct node {
    int payload;
    struct node* leftChild;
    struct node* rightChild;
    
};
// creates a temporary node and allocates memory to it using malloc, null is stored in left and right child
struct node *newNode(int value) 
 {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->payload = value;
    
    node->leftChild = NULL; 
    node->rightChild = NULL;
    return node;
        }
//vistInOrder takes the root of the binary tree and prints the elements in order.
void visitInOrder(struct node *root)
{
    if (root != NULL) 
    {
        visitInOrder(root->leftChild); //left
        cout << root->payload <<" "; //self
        visitInOrder(root->rightChild); //right

    }
}

//insertNode is made to insert a node into the top and is how it gets the values, if the node is null it calls newNode
 
struct node* insertNode(struct node *var, int value)
{
    if (var == NULL)
    return newNode(value);
    {
    if (value <= var->payload)
    {
        var->leftChild = insertNode(var->leftChild, value);
    }
    else if (value > var->payload)
    {
        var->rightChild = insertNode(var->rightChild, value);
    }
    return var;
    }
}
int main(int argc, char** argv)
{
    struct node *root = NULL; // sets the root to null 
    root = insertNode(root, 4); // drops in a 4 first and then the following code drops more elements in the list
    insertNode(root, 1);
    insertNode(root, 0);
    insertNode(root, 8);
    insertNode(root, 2);
    insertNode(root, 7);
    insertNode(root, 12);
    insertNode(root, 9);
    cout << "In Order" << endl;
    visitInOrder(root);
    cout << "" <<endl;
    return 0;
}