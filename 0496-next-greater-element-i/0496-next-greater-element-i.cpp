class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size() ;
        int n2 = nums2.size() ;

        vector<int> ans(n2) ;
        stack<int> s ; 
        unordered_map<int,int> m ; 
        for(int i = n2-1 ; i >-1 ; i--){
            while(s.empty()==false){
                if(s.top()>nums2[i]){
                    m[nums2[i]]=s.top() ;
                    break ; 
                }
                s.pop() ;
            }
            if(s.empty()) m[nums2[i]]=-1 ;
            s.push(nums2[i]) ;
        }
        vector<int>fans(n1) ;
        for(int i = 0 ;i < n1 ; i++){
            fans[i]=m[nums1[i]] ;
        }
        return fans ; 
    }
};