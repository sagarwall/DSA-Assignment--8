#include <bits/stdc++.h>
using namespace std;
class traversal{
  public:
  struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

    void preorder(TreeNode* root){
      if(root == NULL) return 0;
      print(node -> data);
      preorder(node -> left);
      preorder(node -> right);
    }

   void inorder(TreeNode* root){
      if(root == NULL) return 0;
      inorder(node -> left);
      print(node -> data);
      inorder(node -> right);
    }
 void postorder(TreeNode* root){
      if(root == NULL) return 0;
      postorder(node -> left);
      postorder(node -> right);
      print(node -> data);
    }
};
