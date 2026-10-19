class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& v, int k) {
        int n = v.size() ;
        int streak = 0 ; 
        unordered_set<int> s ; 
        for(int i = 0 ; i < n ; i++){
            streak++;
            if(streak<=k+1){
                if(s.find(v[i])==s.end()){
                    s.insert(v[i]) ;
                }else{
                    return true ; 
                }
            }else{
                s.erase(v[i-k-1]) ;
                if(s.find(v[i])!=s.end()){
                    return true ; 
                }
                s.insert(v[i]) ;
            }
        }
        return false ; 
    }
};