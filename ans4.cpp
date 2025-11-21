#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to check if a binary tree is a BST
bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
    if (!root) return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

// Helper function to build a sample tree
Node* newNode(int data) {
    return new Node(data);
}

int main() 
{
    Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);

    if (isBST(root))
        cout << "The tree is a BST" << endl;
    else
        cout << "The tree is NOT a BST" << endl;

    return 0;
}
