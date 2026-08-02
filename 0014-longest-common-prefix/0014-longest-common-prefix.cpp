class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size() ;
        string ans = strs[0] ;

        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < ans.length() ; j++){
                if(strs[i][j]!=ans[j]){
                    ans.erase(j);
                    break ; 
                }
            }
        }

        return  ans ;  

    }
};