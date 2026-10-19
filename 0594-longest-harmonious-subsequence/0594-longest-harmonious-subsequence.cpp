class Solution {
public:
    int findLHS(vector<int>& nums) {
        int longlen=0 ; 
        vector<pair<int,int>> v ; 
        map<int,int> m ; 
        for(int i = 0 ;i < nums.size() ; i++){
            m[nums[i]]++;
        } 
        for(auto it : m ) v.push_back({it.first,it.second}) ;

        int n = v.size() ;

        for(int i = 0 ; i < n-1 ; i++){
            if(v[i+1].first-v[i].first==1) longlen=max(longlen,v[i+1].second+v[i].second) ;
        }

        return longlen ; 
    }
};