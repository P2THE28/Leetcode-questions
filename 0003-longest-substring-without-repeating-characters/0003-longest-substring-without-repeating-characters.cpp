class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length() ;
        unordered_map<char,int> m ; 
        int p1 = 0 ; 
        int p2 = 0 ; 
        int maxlen=INT_MIN ; 
        while(p2<n){
            if(m.find(s[p2])==m.end()){
                m[s[p2]]=p2 ;
                p2++;
            }else{
                maxlen=max(maxlen,p2-p1) ;
                p1=max(m[s[p2]]+1,p1) ;
                m[s[p2]]=p2 ;
                p2++;
            }
        }

        maxlen=max(maxlen,p2-p1) ;

        return maxlen ; 
    }
};