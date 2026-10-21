class Solution {
public:
    static constexpr int N = 1e6 ;
    int isprime[N+1] ;
    
    Solution(){
        for (int i = 0; i <= N; i++) isprime[i] = true;
        isprime[0]=isprime[1]=false ; 
        for(int i = 2 ; i*i <=N ; i++){
            if(isprime[i]){
                for(int j = i*i ; j <=N ; j+=i){
                    isprime[j]=false ; 
                }
            }
        }
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> v ; 
        for(int i = left ; i <=right ; i++){
            if(isprime[i]) v.push_back(i) ;
        }
        if(v.size()<2) return {-1,-1} ;
        vector<int>ans(2) ;
        int diff = v[1]-v[0] ; 
        ans[0]=v[0] ;
        ans[1]=v[1] ; 
        for(int i = 0 ; i < v.size()-1 ;i++){
            if(diff>v[i+1]-v[i]){
                ans[0]=v[i] ;
                ans[1]=v[i+1] ;
                diff=v[i+1]-v[i] ;
            }
        } 
        return ans ; 
    }
};