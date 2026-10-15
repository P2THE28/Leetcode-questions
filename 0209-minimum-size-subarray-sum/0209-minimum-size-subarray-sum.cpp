class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size() ;
        int j = 0 ; 
        int sum = 0 ;
        int ms = INT_MAX ; 
        for(int i = 0 ; i < n ; i++){
            sum+=nums[i] ;
            while(j<n && sum>=target){
                ms=min(ms,i-j+1) ;
                sum-=nums[j++] ;
            }
        }
        return ms==INT_MAX ? 0 : ms ; 
    }
};