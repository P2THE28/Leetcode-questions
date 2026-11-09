class Solution {
public:
    vector<int> findAnagrams(string& s, string p) {
        int ns = s.length() ; 
        int np = p.length() ;

        if(np>ns) return {} ;

        vector<int> ans ; 
        map<char,int> mp,ms ; 
        for(char ch : p) mp[ch]++ ;
        for(int i = 0 ;i < np ; i++)  ms[s[i]]++ ;
        int p1 = 0 , p2 = np-1 ; 
        while(p2<ns){
            if(mp==ms) ans.push_back(p1) ;
            p2++ ;
            if(p2<ns){
                ms[s[p2]]++;
                ms[s[p1]]--;
                if(ms[s[p1]]==0) ms.erase(s[p1]) ;
                p1++;
            }
        }
        return ans ; 
    }
};