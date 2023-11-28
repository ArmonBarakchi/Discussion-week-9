//
// Created by Armon Barakchi on 11/27/23.
//
#include "BinarySearchTree.h"
using namespace std;
#include <iostream>

BinaryTree::BinaryTree(){
    root = nullptr;
}
void BinaryTree::deleteNode(int aVal, BinaryTree::Node *&aNodePtr) {
    if (aVal < aNodePtr->val){
        deleteNode(aVal, aNodePtr->left);
    }
    else if (aVal > aNodePtr-> val){
        deleteNode(aVal, aNodePtr->right);
    }
    else { //if value is correct
        makeDeletion(aNodePtr);
    }
}

void BinaryTree::insert(BinaryTree::Node *&aNodePtr, BinaryTree::Node *&aNewNodePtr) {
    if(aNodePtr == nullptr){
        aNodePtr = aNewNodePtr;
    }
    else if(aNewNodePtr->val < aNodePtr->val){
        insert(aNodePtr->left, aNewNodePtr);
    }
    else {
        insert(aNodePtr->right, aNewNodePtr);
    }
}

void BinaryTree::makeDeletion(BinaryTree::Node *&aNodePtr) {
    Node* tempNodePtr = nullptr;

    if (aNodePtr == nullptr) {
        cout << "Cannot remove empty node" << endl;
    }
    else if (aNodePtr-> right == nullptr){
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->right;
        delete tempNodePtr;
    }
    else if (aNodePtr -> left  == nullptr){
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->left;
        delete tempNodePtr;
    }

    else {
        tempNodePtr = aNodePtr -> right;

        while (tempNodePtr-> left) {
            tempNodePtr = tempNodePtr -> left;
        }

        tempNodePtr -> left = aNodePtr->left;
        tempNodePtr = aNodePtr;
        aNodePtr = tempNodePtr->right;
        delete tempNodePtr;
    }
}



void BinaryTree::insertNode(int aVal) {
Node* newNode = new Node(aVal);
insert(root, newNode);
}

bool BinaryTree::searchNode(int aVal) {
    Node* currentNode = root;
    while(currentNode){
        if(currentNode->val == aVal){
            return true;
        }
        else if (aVal < currentNode->val){
            currentNode = currentNode->left;
        }
        else{
            currentNode = currentNode->right;
        }
    }
    return false;
}

void BinaryTree::remove(int aVal) {

}

BinaryTree::Node::Node( int aval, Node* aLeft, Node* aRight){
    val = aval;
    left = aLeft;
    right = aRight;
}

void BinaryTree::displayInOrder(Node* aNodePtr){
    if (aNodePtr) {
        displayInOrder(aNodePtr->left);
        cout << aNodePtr->val << " ";
        displayInOrder(aNodePtr->right);
    }
}

void BinaryTree::printTree(){
    displayInOrder(root);
    cout << endl;
};