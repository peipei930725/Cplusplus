#include<string>
#include<iostream>

using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        return  TFbool(root,1);
    }
    bool TFbool(TreeNode* root,int n){
        if(root==nullptr) return true;
        if((root->val)%2!=(n%2)){
            return false;
        }
        return TFbool(root->left,n+1) && TFbool(root->right,n+1);
    }
};

int main(){
    Solution s;
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(10);
    root->right=new TreeNode(4);
    // root->left->left=new TreeNode(3);
    // root->left->right=new TreeNode(7);
    // root->right->left=new TreeNode(9);
    // root->right->right=new TreeNode(5);
    cout<<s.isEvenOddTree(root);
    return 0;
}