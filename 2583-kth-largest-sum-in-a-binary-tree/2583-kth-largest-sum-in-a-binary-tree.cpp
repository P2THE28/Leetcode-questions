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
    vector<long long> arr ; 
    void kthlevel(TreeNode* root){
        queue<TreeNode*> q ; 
        q.push(root);
        q.push(NULL) ;
        long long sum = 0 ; 
        while(!q.empty()){
            TreeNode* temp = q.front() ;
            q.pop() ;
            if(temp==NULL){
                arr.push_back(sum) ;
                sum=0;
                if (!q.empty()) q.push(NULL);
                continue ; 
            }
            if(temp->left!=NULL) q.push(temp->left) ;
            if(temp->right!=NULL) q.push(temp->right) ;
            sum+=temp->val ; 
        }
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        arr.clear() ;
        kthlevel(root) ;
        if(arr.size()<k){
            return -1 ; 
        }

        sort(arr.rbegin(),arr.rend()) ;
        return arr[k-1] ;
    }
};