class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m ;
        int n = nums.size() ; 

        for(int i : nums )  m[i]++ ;

        vector<vector<int>> v ; 
        
        for(auto it : m ) v.push_back({it.second,it.first}) ;

        sort(v.rbegin(),v.rend()) ;

        vector<int> ans(k) ; 
        for(int i = 0 ; i < k ; i++){
            ans[i]=v[i][1] ;
        }

        return ans ; 

    }
};