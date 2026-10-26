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
    bool same(TreeNode* p , TreeNode* q ){
        if(p==NULL || q==NULL) return p==q ; 
        bool leftsame  = same(p->left,q->left) ;
        bool rightsame = same(p->right,q->right) ;
        return leftsame && rightsame && (p->val == q->val) ;
    }

    bool search(TreeNode* root , TreeNode* subroot){
        if(root==NULL) return false ; 
        bool found=false;
        if(root->val==subroot->val) found = same(root,subroot) ;
        return found || search(root->left,subroot) || search(root->right,subroot) ;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return search(root,subRoot) ;
    }
};