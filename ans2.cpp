#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert into BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

//
// (a) SEARCH (RECURSIVE)
//
Node* searchRecursive(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

//
// (a) SEARCH (NON-RECURSIVE)
//
Node* searchNonRecursive(Node* root, int key) {
    while (root) {
        if (root->data == key) return root;
        else if (key < root->data) root = root->left;
        else root = root->right;
    }
    return nullptr;
}

//
// (b) MAXIMUM ELEMENT OF BST
//
Node* findMax(Node* root) {
    if (!root) return nullptr;
    while (root->right) root = root->right;
    return root;
}

//
// (c) MINIMUM ELEMENT OF BST
//
Node* findMin(Node* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

//
// (d) IN-ORDER SUCCESSOR OF A NODE
//
Node* inorderSuccessor(Node* root, Node* node) {
    if (!root || !node) return nullptr;

    // Case 1: Node has right subtree → successor = leftmost of right subtree
    if (node->right)
        return findMin(node->right);

    // Case 2: No right subtree → successor = nearest ancestor for which node is in left subtree
    Node* succ = nullptr;
    while (root) {
        if (node->data < root->data) {
            succ = root;
            root = root->left;
        } else if (node->data > root->data)
            root = root->right;
        else
            break;
    }
    return succ;
}

//
// (e) IN-ORDER PREDECESSOR OF A NODE
//
Node* inorderPredecessor(Node* root, Node* node) {
    if (!root || !node) return nullptr;

    // Case 1: Node has left subtree → predecessor = rightmost of left subtree
    if (node->left)
        return findMax(node->left);

    // Case 2: No left subtree → predecessor = nearest ancestor for which node is in right subtree
    Node* pred = nullptr;
    while (root) {
        if (node->data > root->data) {
            pred = root;
            root = root->right;
        } else if (node->data < root->data)
            root = root->left;
        else
            break;
    }
    return pred;
}

// Inorder Traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    // Create BST
    int values[] = {20, 8, 22, 4, 12, 10, 14};
    for (int x : values) root = insert(root, x);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    int key = 10;

    // Search recursive
    Node* sr = searchRecursive(root, key);
    cout << "\nSearch Recursive (" << key << "): " 
         << (sr ? "Found" : "Not Found") << endl;

    // Search non-recursive
    Node* sn = searchNonRecursive(root, key);
    cout << "Search Non-Recursive (" << key << "): " 
         << (sn ? "Found" : "Not Found") << endl;

    // Minimum & Maximum
    cout << "\nMinimum element: " << findMin(root)->data << endl;
    cout << "Maximum element: " << findMax(root)->data << endl;

    // Successor and Predecessor
    Node* succ = inorderSuccessor(root, sr);
    Node* pred = inorderPredecessor(root, sr);

    cout << "\nInorder Successor of " << key << ": ";
    succ ? cout << succ->data : cout << "None";
    cout << endl;

    cout << "Inorder Predecessor of " << key << ": ";
    pred ? cout << pred->data : cout << "None";
    cout << endl;

    return 0;
}
