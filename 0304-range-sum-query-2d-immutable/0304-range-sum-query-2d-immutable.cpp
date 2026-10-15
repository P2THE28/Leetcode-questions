class NumMatrix {
public:
    vector<vector<int>> &v ; 
    NumMatrix(vector<vector<int>>& matrix) : v(matrix) {
        v=matrix ; 
        for(int r = 0 ; r < matrix.size() ;r++){
            for(int c = 0 ; c < matrix[0].size() ; c++){
                if(r>0) v[r][c]+=v[r-1][c] ;
                if(c>0) v[r][c]+=v[r][c-1] ;
                if(r>0 && c>0) v[r][c]-=v[r-1][c-1] ;
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = v[row2][col2] ;
        if(col1>0) sum-=v[row2][col1-1] ;
        if(row1>0) sum-=v[row1-1][col2] ;
        if(row1>0 && col1>0) sum+=v[row1-1][col1-1] ;
        return sum ; 
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */