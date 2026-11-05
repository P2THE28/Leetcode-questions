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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* , unsigned long long  > > q ; 
        q.push({root,0}) ;
        unsigned long long  maxlen = 0 ; 
        while(!q.empty()){
            unsigned long long  st = q.front().second ; 
            unsigned long long  end = q.back().second ; 
            maxlen= max(maxlen,end-st+1) ;
            long long  sz = q.size() ;

            for(int i = 0 ; i < sz ; i++){
                auto  idx = q.front().second ; 
                TreeNode* temp = q.front().first ; 
                if(temp->left!=NULL) q.push({temp->left,idx*2+1}) ;
                if(temp->right!=NULL) q.push({temp->right,idx*2+2}) ;
                q.pop() ;
            }
        }
        return maxlen ; 
    }
};