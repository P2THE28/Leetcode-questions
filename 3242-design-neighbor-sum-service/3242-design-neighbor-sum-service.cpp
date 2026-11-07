class NeighborSum {
public:
    vector<vector<int>> v ; 
    int n ;
    NeighborSum(vector<vector<int>>& grid) {
        v = grid ; 
        n=grid.size() ;
    }

    

    pair<int,int> search(int val ){
        int idx1 , idx2 ; 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(v[i][j]==val) {
                    idx1 = i ; 
                    idx2 = j ; 
                    break ; 
                }
            }
        }
        return {idx1 , idx2} ;
    }

    int adjacentSum(int value) {
        pair<int,int> idx = search(value) ;
        int i = idx.first ; 
        int j = idx.second ; 
        int sum = 0 ; 
        
        if(i>0) sum+= v[i-1][j] ; 
        if(j>0) sum+= v[i][j-1] ;
        if(i<n-1) sum+= v[i+1][j] ;
        if(j<n-1) sum+=v[i][j+1] ;
    
        return sum ; 
    }
    
    int diagonalSum(int value) {
        pair<int,int> idx = search(value) ;
        int i = idx.first ; 
        int j = idx.second ; 
        int sum = 0 ; 
    
        if(i>0 && j<n-1 ) sum+= v[i-1][j+1] ; 
        if(j>0 && i<n-1 ) sum+= v[i+1][j-1] ;
        if(i>0 && j>0) sum+= v[i-1][j-1] ;
        if(i<n-1 && j<n-1)sum+= v[i+1][j+1] ;
   
        return sum ; 
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */