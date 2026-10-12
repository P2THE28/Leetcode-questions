class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans ; 
        deque<int> dq ; 
        int j = 0 ; 
        while(j<k){
            if(!dq.empty() && nums[dq.back()] <= nums[j]){
                dq.pop_back() ;
            }else{
                dq.push_back(j++) ;
            }
        }
        ans.push_back(nums[dq.front()]) ;
     
        for(int i = k ; i < nums.size() ; i++){
            while(!dq.empty() && dq.front()<=i-k) {
                dq.pop_front() ;
            }

            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back() ;
            }
            dq.push_back(i) ;
            ans.push_back(nums[dq.front()]) ;
        }
        return ans ; 
    }
};