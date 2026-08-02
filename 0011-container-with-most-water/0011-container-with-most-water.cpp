class Solution {
public:
    int maxArea(vector<int>& v) {
        int n = v.size() ;
        int i = 0 ; 
        int j = n-1 ;
        int maxwater=0;
        while(i<j){
            maxwater=max(maxwater,(j-i)*min(v[i],v[j])) ;
            if(v[i]>v[j]){
                j--;
            }else{
                i++;
            }
        }
        return maxwater ;
    }
};