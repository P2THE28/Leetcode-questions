class Solution {
public:
    int findLHS(vector<int>& nums) {
        int longlen=0 ; 
        unordered_set<int> s ; 
        unordered_map<int,int> m ; 
        for(int i = 0 ;i < nums.size() ; i++){
            m[nums[i]]++;
            s.insert(nums[i]) ;
        } 
        
        for(auto it : m){
            int num1 = it.first ; 
            if(s.find(num1-1)!=s.end()){
                longlen=max(longlen,m[num1]+m[num1-1]) ;
            }
        }

        return longlen ; 
    }
};