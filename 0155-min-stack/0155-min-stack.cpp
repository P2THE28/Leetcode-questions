class MinStack {
private :
long long int  minvalue ;
stack<long long int > s ; 
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(s.empty()){
            minvalue = value ; 
            s.push(value) ;
        }else if(value<minvalue){
            s.push((long long)2*value - minvalue) ;
            minvalue = value ; 
        }else{
            s.push(value) ;
        }
    }
    
    void pop() {
        if(s.top()<minvalue){
            minvalue=2*minvalue-s.top() ;  
        }
        s.pop() ;
    }
    
    int top() {
        if(s.size()!=0 && minvalue>s.top()){
            return minvalue ; 
        }
        return s.top() ;
    }
     
    int getMin() {
        return minvalue ; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */