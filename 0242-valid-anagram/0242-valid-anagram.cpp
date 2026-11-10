class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26,0) ;

        for(char ch : s ) v[ch-'a']++;
        for(char ch : t ) v[ch-'a']--;

        int cnt=0 ; 

        for(int i : v) {
            if(i==0) cnt++ ;
        }

        return cnt==26 ? true : false ; 
    }
};