/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void path(vector<string>& ans , string s , TreeNode* root){
        if(root->left == NULL && root->right==NULL ){
            ans.push_back(s) ;
            return ; 
        }
        if(root->left!=NULL)  path(ans,s+"->" + to_string(root->left->val),root->left) ;
        if(root->right!=NULL) path(ans,s+"->" + to_string(root->right->val),root->right) ;
        return ; 
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans ;
        if(root==NULL) return ans ; 
        string s=to_string(root->val);  
        path(ans,s,root) ;
        return ans ; 
    }
};