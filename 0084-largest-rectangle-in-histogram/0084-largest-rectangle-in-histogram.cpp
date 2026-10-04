class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size() ;
        vector<int> r(n), l(n)  ; 
        stack<int> s ; 
        for(int i= 0 ; i < n; i++){
            while(s.empty()==false &&heights[s.top()]>=heights[i] ){
                s.pop() ;
            }
            l[i]= s.empty() ? -1 : s.top() ;
            s.push(i) ;
        }

        while(s.empty()==false){
            s.pop() ;
        }

        for(int i= n-1 ; i>=0; i--){
            while(s.empty()==false && heights[s.top()]>=heights[i]){
               s.pop() ;
            }
            r[i]= s.empty() ? n : s.top() ;
            s.push(i) ;
        }


        int maxarea = INT_MIN ; 
        for(int i = 0 ; i < n; i++){
            maxarea=max(maxarea,heights[i]*(r[i]-l[i]-1)) ;
        }
        return maxarea ; 
    }
};