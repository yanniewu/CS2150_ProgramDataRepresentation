// Insert your header information here
//ylw4j
//October 4th, 2021
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <stack>
#include <ctype.h>
#include <cstdlib>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
    cleanTree(expressionStack.top());
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
    if (tree != NULL){
        cleanTree(tree->right);
        cleanTree(tree->left);
        delete tree;
    }
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
    TreeNode *n = new TreeNode(val);

    if(!isdigit(val[0]) && val.length() == 1){
        TreeNode *right = expressionStack.top();
        expressionStack.pop();
        TreeNode *left = expressionStack.top();
        expressionStack.pop();
        n->right = right;
        n->left = left;
    }
    
    expressionStack.push(n);

}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format 

    if(tree != NULL){
        cout << tree->value << " ";
        printPrefix(tree->left);
        printPrefix(tree->right);
    }

}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses

    //Traverses left subtree
    if(tree->left != NULL){
        cout << "(";
        printInfix(tree->left);
    }

    //Formats infix expression with correct spacing
    string val = tree->value;
    if(!isdigit(val[0]) && val.length() == 1){
        cout << " " << tree->value << " ";
    }
    else{
        cout << tree->value;
    }

    //Traverses right subtree
    if(tree->right != NULL){
        printInfix(tree->right);
        cout << ")";

    }

}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
    
    if(tree != NULL){
        printPostfix(tree->left);
        printPostfix(tree->right);
        cout << tree->value << " ";
    }

}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } 

    else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result

    if(tree == NULL){
        return 0;
    }
    
    string x = tree->value;

    if(x == "+"){
        return (calculate(tree->left) + calculate(tree->right));
        cout << tree ->value;
    }

    else if(x == "-"){
        return (calculate(tree->left) - calculate(tree->right));
        cout << tree ->value;
    }

    else if(x == "*"){
        return (calculate(tree->left) * calculate(tree->right)); 
        cout << tree ->value;       
    }

    else if(x == "/"){
        return (calculate(tree->left) / calculate(tree->right));
        cout << tree ->value;
    }

    else{
        return atoi(x.c_str());
    }

}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
    int ans = calculate(expressionStack.top());
    return ans;
}
