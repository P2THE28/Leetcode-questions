class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size() ;
        double average = INT_MIN ; 
        double sum=0 ;
        for(int i = 0 ; i < n ; i++){
            if(i<k){
                sum+=nums[i] ;
            }else{
                average=max(average,sum/k) ;
                sum+=nums[i]-nums[i-k] ;
            }
        }
        average = max(average,sum/k) ;

        return average ; 
    }
};