class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size() ;
        int st = 0 ; 
        int end = n-1 ; 
        while(st!=end){
            if(nums[st]<nums[end]){
                st++;
            }else{
                end--;
            }
        }

        return st ; 
    }
};