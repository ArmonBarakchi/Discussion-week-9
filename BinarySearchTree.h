//
// Created by Armon Barakchi on 11/27/23.
//

#ifndef DISCUSSIONWEEK9_BINARYSEARCHTREE_H
#define DISCUSSIONWEEK9_BINARYSEARCHTREE_H


class BinaryTree {
private:
    struct Node {
        int val;
        Node *left;
        Node *right;

        Node( int aval, Node* aLeft = nullptr, Node* aRight = nullptr);
    };

    Node* root;
private:
    void insert(Node* &aNodePtr, Node* &aNewNodePtr);
    void deleteNode(int aVal, Node* &aNodePtr);
    void makeDeletion(Node* &aNodePtr);
public:

    BinaryTree();
    void insertNode(int aVal);
    bool searchNode(int aVal);
    void remove(int aVal);
    void displayInOrder(Node* aNodePtr);
    void printTree();
};
#endif //DISCUSSIONWEEK9_BINARYSEARCHTREE_H
