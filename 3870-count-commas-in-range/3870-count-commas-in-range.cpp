class Solution {
public:
    int countCommas(int n) {
        int cn=3; 
        int comas = 0 ;
        int pre= 999 ; 
        int c = 9999 ;
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