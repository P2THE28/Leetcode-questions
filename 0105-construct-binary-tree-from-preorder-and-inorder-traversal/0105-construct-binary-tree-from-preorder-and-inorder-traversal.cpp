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
    int search(vector<int> & v , int target , int st , int end ){
        int pos  ; 
        for(int i = st ; i <=end ; i++){
            if(v[i]==target){
                pos = i ; 
                break ; 
            } 
        }
        return pos ; 
    }
    TreeNode* maketree(vector<int>& preorder , vector<int>& inorder , int st , int end , int & idx ){
        if(st>end) return NULL ; 
        TreeNode* root = new TreeNode(preorder[idx]) ;

        int pos = search(inorder,root->val,st,end) ; 
        idx++;
        root->left = maketree(preorder,inorder , st , pos-1 , idx) ;
        root->right = maketree(preorder, inorder , pos+1 , end ,idx) ;

        return root ; 
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size() - 1 ; 
        int idx = 0 ; 
        return maketree(preorder,inorder,0,n,idx) ;
    }
};