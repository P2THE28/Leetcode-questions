class Solution {
public:
    bool ispalindrome(string s){
        int n = s.length() ;
        int i = 0 ; 
        int j = n-1 ; 
        while(i<=j){
            if(s[i]!=s[j]) return false ; 
            i++,j--;
        }
        return true ; 
    }

    void solve(string s , vector<string> &temp , vector<vector<string>> &ans  ){
        int n = s.length() ;
        if(n==0) ans.push_back(temp) ;
        for(int i = 0 ; i < n ; i++){ 
            string part1 = s.substr(0,i+1) ;
            string part2 = s.substr(i+1,n-i-1);
            if(ispalindrome(part1)) {
                temp.push_back(part1) ;
                solve(part2,temp,ans) ;
                temp.pop_back() ;
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans ; 
        vector<string> temp ; 
        solve(s,temp,ans) ;
        return ans ; 
    }
};