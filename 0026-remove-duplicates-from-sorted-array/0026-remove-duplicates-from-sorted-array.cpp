class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> expectedNums ; 
        for(int i = 0 ;i < nums.size() ; i++){
            if(i>0 && nums[i]==nums[i-1]) continue ;  
            expectedNums.push_back(nums[i]) ;
        }
        
        int k = expectedNums.size() ;
        for(int i = 0 ; i < k ; i++) nums[i]=expectedNums[i] ;
        return k ; 
    }
};