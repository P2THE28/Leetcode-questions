class Solution {
public:
    set<vector<int>> s ;
    void solve(vector<int> arr , vector<vector<int>> &ans , vector<int>&comb , int i , int target){
        // base case 
        if(i==arr.size() || target <0) return ;
        if(target==0){
            if(s.find(comb)==s.end()){
                ans.push_back(comb) ;
                s.insert(comb) ;
            }
            return ;
        }

        comb.push_back(arr[i]);
        solve(arr,ans,comb,i+1,target-arr[i]);
        solve(arr,ans,comb,i,target-arr[i]);
        comb.pop_back() ;
        solve(arr,ans,comb,i+1,target) ;
    
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>>ans ;
        vector<int>comb;
        solve(arr,ans,comb,0,tar) ;
        return ans ;
    }
};