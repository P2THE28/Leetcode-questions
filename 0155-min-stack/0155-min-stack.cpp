class MinStack {
private :
vector<int> stack ;
vector<int> minval ;

int tp ; 
public:

    MinStack() {
        tp= -1 ; 
    }
    
    void push(int value) {
        stack.push_back(value) ;
        if(tp==-1){
            minval.push_back(value) ;
        }else{
            minval.push_back(min(value,minval[tp])) ;
        }
        tp++;
    }
    
    void pop() {
        if(tp!=-1){
            stack.pop_back() ;
            minval.pop_back() ;
            tp--;
        }
    }
    
    int top() {
        return stack[tp] ;
    }
    
    int getMin() {
        return minval[tp] ; 
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