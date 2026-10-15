class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size() ;
        int i = 0 , j = 0 ; 
        int sum = nums[0] ;
        int ms = INT_MAX ; 
        do{
            if(j<n-1 && sum<target){
                sum+=nums[++j] ;
            }else if(sum>=target){
                ms=min(ms,j-i+1) ;
                sum-=nums[i++] ;
                if(i>j && i<n){
                    j=i ; 
                    sum=nums[i] ;
                }
            }else{
                break ; 
            }
        }while(j<n && i<n) ;
        return ms==INT_MAX ? 0 : ms ; 
    }
};