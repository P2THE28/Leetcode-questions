class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size() ;
        int n2 = nums2.size() ;

        vector<int> ans(n2) ;
        stack<int> s ; 
        for(int i = n2-1 ; i >-1 ; i--){
            while(s.empty()==false){
                if(s.top()>nums2[i]){
                    ans[i]=s.top() ;
                    break ; 
                }
                s.pop() ;
            }
            if(s.empty()) ans[i]=-1 ;
            s.push(nums2[i]) ;
        }
        vector<int>fans(n1) ;
        for(int i = 0 ;i < n1 ; i++){
            int idx = find(nums2.begin(),nums2.end(),nums1[i]) - nums2.begin() ;
            fans[i]=ans[idx] ;
        }
        return fans ; 
    }
};