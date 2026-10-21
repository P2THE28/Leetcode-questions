class Solution {
public:
    bool ispal(string s , int l , int r ){
        while(l<=r){
            if(s[l]==s[r]){
                l++ , r-- ;
            }else{
                return false ; 
            }
        }
        return true  ; 
    }

    bool validPalindrome(string s) {
        int n = s.length() ;
        int p1 = 0 ; 
        int p2 = n-1 ; 
        while(p1<=p2){
            if(s[p1]==s[p2]){
                p1++ , p2-- ; 
            }else{
                return (ispal(s,p1+1,p2) ? true : ispal(s,p1,p2-1) );  
            }
        }
        return true ; 
    }
};