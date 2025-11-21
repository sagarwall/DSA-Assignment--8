#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//QUESTION 3(A)
TreeNode * instertintobst ( TreeNode * root , int val ){
  if(root == NULL) return new TreeNode(val);
    TreeNode * cur = root;
    while(true){
      if(cur -> data <= val){
        if( cur -> right != NULL) cur = cur->right;
          else{
              cur -> right = new TreeNode(val);
              break;
          }
      }
else{
if (cur -> left != NULL) cur = cur -> left;
else {
    cur-> left = new TreeNode(val);
    break;
}
}
return root;
    }
};


//QEUSTION 3 (B)
TreeNode* deletefrombst( TreeNode* root , int val){
  if(root == NULL) return NULL;
if(root-> val == key){
  return helper(root);
}
TreeNode* dummy = root;
if(root -> val <= val){
  if(root -> left != NULL && root -> left -> val == key){
    root -> left = helper(root -> left);
  break;
  }
else{
root = root -> left;
  }
} else
    {
      if(root -> right != NULL && root -> right -> val == key){
      root -> right = helper (root -> right);
      break;
      }
else{
    root = root -> right;
}
    }
}
TreeNode* helper( TreeNode* root){
  if(root -> left == NULL) return root -> right;
if (root -> right == NULL ) return root -> left;
TreeNode* rightchild = root -> right;
TreeNode * rightmost = findrightmost(root -> left);
rightmost -> right = rightchild;
return root -> left;
}
TreeNode* findlastright(TreeNode* root){
  if (root -> right == NULL) reutrn root;
}
};




//QUESTION 3(C)
TreeNode* maximumdepth( TreeNode* root){
    if(root == NULL) return 0;
int lh = maximumdepth(root -> left);
int rh = maximumdepth (root -> right);
return 1+ max(lh , rh);
};

    

//QUESTION3(D)
int mindepth(TreeNode* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right != NULL)
        return mindepth(root->right) + 1;
    if (root->right == NULL && root->left != NULL)
        return mindepth(root->left) + 1;
    if (root->left != NULL && root->right != NULL)
        return min(mindepth(root->left), mindepth(root->right)) + 1;
    return 1;
}
