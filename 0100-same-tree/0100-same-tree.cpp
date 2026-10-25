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
    void bfs(vector<int>& arr , queue<TreeNode*>& qe , TreeNode* root){
        qe.push(root) ;
        while(qe.size()>0){
            TreeNode* curr = qe.front() ;
            qe.pop() ;
            if(curr==NULL){
                arr.push_back(1e4+1) ;
                continue ; 
            }else{
                arr.push_back(curr->val) ;
            }
            qe.push(curr->left) ; 
            qe.push(curr->right) ; 
        }
        return ; 
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> arr1 ; 
        vector<int> arr2 ; 
        queue<TreeNode*> qe ; 
        bfs(arr1,qe,p) ;
        bfs(arr2,qe,q) ;

        return arr1==arr2 ;  
    }
};