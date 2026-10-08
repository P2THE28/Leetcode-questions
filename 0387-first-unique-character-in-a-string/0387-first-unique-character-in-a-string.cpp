class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>m ;
        queue<int> q ; 
        for(int i = 0 ; i < s.length() ;i++){
            if(m.find(s[i])==m.end()) q.push(i) ;
            m[s[i]]++;
        }

        while(!q.empty()){
            char c = s[q.front()] ;
            if(m[c]==1) {
                return q.front() ;
            }
            q.pop() ;
        }
        return -1 ; 
    }
};