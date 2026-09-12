class Solution {
public:
    long long countCommas(long long n) {
        long long cn=3; 
        long long comas = 0 ;
        long long pre= 999 ; 
        long long c = 9999 ;
        if(n<1000){
            return 0 ; 
        }else{
            while(c<n){
                comas+=(c-pre)*(cn/3) ;
                cn++;
                pre=c ;
                c=c*10+9 ;
            }
            comas+=(n-pre)*(cn/3) ;
            return comas ; 
        }
        
    }
};