#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
    insert(root, x);
}

//private helper to insert node
void AVLTree::insert(AVLNode*& n, const string& x) {
    if(n == NULL){
        n = new AVLNode();
        n-> value = x;
    }
    else if(x < n->value){
        insert(n->left, x);
    }
    else if(x > n->value){
        insert(n->right, x);
    }
    else;
    n->height = 1 + max(height(n->right), height(n->left));
    balance(n);
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    if(!find(x)){
    return "";
    }

    else{
        return pathTo(root, x);
    }
}

//Private helper to find path of x
string AVLTree::pathTo(AVLNode* n, const string& x) const{
   if(x < n->value){
        return n->value + " " + pathTo(n->left, x);
    }
    else if(x > n->value){
        return n->value + " " + pathTo(n->right, x);
    }
    else{
        return n->value;
    }

}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    return find(root, x);
}

//Private helper to find x
bool AVLTree::find(AVLNode* n, const string& x) const{
    if(n == NULL){
        return false;  //we've "run off" the bottom
    }
    else if(x < n->value){
        return find(n->left, x);  //search left
    }
    else if(x > n->value){
        return find(n->right, x);  //search right
    }
    else{
        return true; //matched
    }
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
    return numNodes(root);
}

int AVLTree::numNodes(AVLNode* n) const{
    if(n==NULL){
        return 0;
    }

    return 1 + numNodes(n->right) + numNodes(n->left);
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    int balanceFactor = height(n->right) - height(n->left);
    
    //Rotates left
    if(balanceFactor == 2){
        int rotationCheck =  height(n->right->right) - height(n->right->left);
        if(rotationCheck < 0){
            n->right = rotateRight(n->right);
        }
        n = rotateLeft(n);
    }

    //Rotates right
    if(balanceFactor == -2){
        int rotationCheck =  height(n->left->right) - height(n->left->left);
        if(rotationCheck > 0){
            n->left = rotateLeft(n->left);
        }
        n = rotateRight(n);
    }
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    AVLNode* rightChild = n->right;
    AVLNode* temp = rightChild->left;

    rightChild->left = n;
    n->right = temp;


    //Updates height
    n->height = 1 + max(height(n->right), height(n->left));
    rightChild->height = 1 + max(height(rightChild->right), height(rightChild->left));

    return rightChild;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    AVLNode* leftChild = n->left;
    AVLNode* temp = leftChild->right;

    leftChild->right = n;
    n->left = temp;

    //Updates height
    n->height = 1 + max(height(n->right), height(n->left));
    leftChild->height = 1 + max(height(leftChild->right), height(leftChild->left));

    return leftChild;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
