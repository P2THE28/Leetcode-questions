class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ;
        int ans = 0 ; 
        vector<int> l(n) , r(n) ; 
       
        int maxh = height[0] ;
        for(int i = 0 ; i < n ; i++){
            maxh=max(maxh,height[i]) ;
            l[i]=maxh ;
        }
        maxh=height[n-1] ;
        for(int i = n-1 ; i >=0 ; i--){ 
            maxh=max(maxh,height[i]) ;
            r[i]=maxh ;
        }


        for(int i = 0 ; i < n ; i++){
            ans+= min(l[i],r[i]) - height[i] ; 
        }
        return ans ; 
    }
};