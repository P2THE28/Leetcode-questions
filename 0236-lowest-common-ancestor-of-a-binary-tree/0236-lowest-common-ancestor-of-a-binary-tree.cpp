/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //method1 :
    vector<vector<TreeNode*>> ans ; 
    void search(TreeNode* root ,TreeNode* p ,TreeNode* q , vector<TreeNode*>&arr ){
        if(root==NULL) return ; 
        if(root==p || root==q){
            ans.push_back(arr) ;
        }
        arr.push_back(root->left) ; 
        search(root->left,p,q,arr);
        arr.pop_back() ;
        arr.push_back(root->right);
        search(root->right,p,q,arr) ;
        arr.pop_back() ;
        return ; 
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans.clear() ;
        vector<TreeNode*> arr ;
        arr.push_back(root) ;
        search(root,p,q,arr) ;
        TreeNode* node = NULL ; 
        for(int i = 0 ; i < min(ans[0].size(),ans[1].size()) ; i++){
            if(ans[0][i]==ans[1][i]) node = ans[0][i] ;
            else  break ; 
        }
        return node ; 
    }
};