class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size() ;
        vector<int> r(n), l(n)  ; 
        stack<int> s1 ; 
        for(int i= 0 ; i < n; i++){
            while(s1.empty()==false){
                if(heights[s1.top()]<heights[i]){
                    l[i]=s1.top() ;
                    break ; 
                }else{
                    s1.pop() ;
                }
            }
            if(s1.empty()) l[i]=-1 ;
            s1.push(i) ;
        }

        stack<int> s2 ; 
        for(int i= n-1 ; i>=0; i--){
            while(s2.empty()==false){
                if(heights[s2.top()]<heights[i]){
                    r[i]=s2.top() ;
                    break ; 
                }else{
                    s2.pop() ;
                }
            }
            if(s2.empty() )r[i]=n ;
            s2.push(i) ;
        }
        int maxarea = INT_MIN ; 
        for(int i = 0 ; i < n; i++){
            maxarea=max(maxarea,heights[i]*(r[i]-l[i]-1)) ;
        }
        return maxarea ; 
    }
};