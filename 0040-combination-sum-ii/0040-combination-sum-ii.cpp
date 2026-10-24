class Solution {
public:
    void solve(vector<int> & candidates , int &target ,  int sum , int idx , vector<int> &temp ,vector<vector<int>> &ans  ){
        if(sum==target){
            ans.push_back(temp) ;
            return ; 
        }


        for(int i = idx ; i < candidates.size() ; i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue ; 
            if(sum+candidates[i]>target) break ; 

            temp.push_back(candidates[i]) ;
            solve(candidates,target,sum+candidates[i],i+1,temp,ans) ;
            temp.pop_back() ;
        } 

        return ; 
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp ; 
        vector<vector<int>> ans ;  
        sort(candidates.begin(),candidates.end()) ;
        solve(candidates, target , 0 , 0 , temp , ans) ;
        return ans ; 
    }
};