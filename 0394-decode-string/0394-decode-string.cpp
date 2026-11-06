class Solution {
public:
    string decodeString(string s) {
        stack<string> st ; 
        int n = s.length() ;
        for(int i = 0 ; i < n ;i++){
            if(s[i]==']'){
                string word = "" ;
                string num = "" ;

                while(st.top()!="["){
                    word= st.top() + word ;
                    st.pop() ;
                }

                st.pop() ;

                while(!st.empty() && "0" <=st.top() && st.top() <="9" ){
                    num=st.top() + num ; 
                    st.pop() ;
                }

                int num1 = stoi(num) ;
                string ans = "" ;
                while(num1--) {
                    ans+=word ; 
                }

                st.push(ans) ;
            }else{
                st.push(string(1, s[i])) ;
            }
        }

        string result = "" ;

        while(!st.empty()){
            result = st.top() + result ; 
            st.pop() ;
        }

        return result ;
    }
};