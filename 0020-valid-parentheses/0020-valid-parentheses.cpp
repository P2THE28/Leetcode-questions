class Solution {
public:
    bool isValid(string s) {
        stack<char>st ; 
        for(char ch : s){
            if(ch==')'){
                if(st.empty()) return false ; 
                char c = st.top() ;
                if(c=='(') {
                    st.pop() ;
                    continue ; 
                }else{
                    return false ; 
                } 
            }

            if(ch==']'){
                if(st.empty()) return false ; 
                char c = st.top() ;
                if(c=='[') {
                    st.pop() ;
                    continue ; 
                }else{
                    return false ; 
                } 
            }

            if(ch=='}'){
                if(st.empty()) return false ; 
                char c = st.top() ;
                if(c=='{') {
                    st.pop() ;
                    continue ; 
                }else{
                    return false ; 
                } 
            }
            st.push(ch) ;
        }

        return (st.empty() ?  true  : false) ; 
    }
};