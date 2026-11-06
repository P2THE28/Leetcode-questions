class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s ; 
        for(auto ch : tokens){
            if(ch=="+" || ch=="-" || ch == "*" || ch=="/"){
                int num2 = s.top() ;
                s.pop() ;
                int num1 = s.top() ;
                s.pop() ;
                if(ch == "+" ){
                    s.push(num1+num2) ;
                }else if (ch=="-" ){
                    s.push(num1-num2) ;
                }else if(ch == "*" ){
                    s.push(num1*num2) ;
                }else if(ch=="/"){  
                    s.push(num1/num2) ;
                }
            
            }else {
                s.push(stoi(ch)) ;
            }
        }

        return s.top() ;
    }
};