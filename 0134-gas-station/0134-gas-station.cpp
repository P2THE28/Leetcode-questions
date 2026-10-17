class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size() ;
        int tsum = 0 ; 
        for(int i = 0 ;i < n ;i ++) {
            gas[i]=gas[i]-cost[i] ;
            tsum+=gas[i] ;
        }

        if(tsum<0){
            return -1 ; 
        }else{
            int sum = gas[0]; 
            queue<int> en ; 
            int  p = 1 ; 
            en.push(0) ;
            while(en.front()!=p%n){
                while(sum<0){
                    sum-=gas[en.front()] ;
                    en.pop() ;
                }
                en.push(p%n) ;
                sum+=gas[p%n] ;
                p++;
            }
            return en.front() ;
        }
    }
};