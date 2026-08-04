class Solution {
public:
    int numberOfSubarrays(vector<int>& v, int k) {
        int n = v.size() ;
        vector<int>pre(n,0) ;
        for(int i = 0 ;i < n ; i++){
            if(v[i]%2==1) pre[i]+=1;
            if(i>0) pre[i]+=pre[i-1] ;
        }

        unordered_map<int,int> m ;
        int c = 0 ; 
        m[0]=1;
        for(int i = 0 ; i < n ; i++){
            int b = pre[i]-k ;
            if(m.find(b)!=m.end()) c+=m[b] ;
            m[pre[i]]++;
        }
        return c ;
    }
};