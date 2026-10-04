class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size() ;
        stack<int> s ;
        vector<int> next(2*n) , ans(n) ; 
        // nums.resize(n+n) ;
        // for(int i = n ; i<2*n ; i++){
        //     nums[i]=nums[i-n] ;
        // }
        // for(int i = 2*n-1 ; i >=0 ; i--){
        //     while(s.size()!=0 && s.top()<=nums[i]){
        //         s.pop() ;
        //     }
        //     next[i]= (s.empty() ? -1 : s.top()) ;
        //     s.push(nums[i]) ;
        // }

        for(int i = 2*n-1 ; i >=0 ; i--){
            while(s.size()!=0 && s.top()<=nums[i%n]){
                s.pop() ;
            }
            next[i]= (s.empty() ? -1 : s.top()) ;
            s.push(nums[i%n]) ;
        }


        for(int i = 0 ;i < n ; i++){
            ans[i]=next[i] ;
        }
  
        return ans ; 
    }
};