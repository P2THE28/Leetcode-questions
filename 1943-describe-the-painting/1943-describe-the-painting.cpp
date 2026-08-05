class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int n=segments.size() ;

        vector<vector<long long>> ans ;
        unordered_set<int> s;

        int maxend = segments[0][0] ;
        int minend = segments[0][0] ;
        for(int i = 0 ; i<n  ; i++){
            maxend=max(maxend,segments[i][1]) ;
            minend=min(minend,segments[i][0]) ;
            s.insert(segments[i][1]);
            s.insert(segments[i][0]);
        }

        vector<long long>diff(maxend+2) ;

        for(int i = 0 ; i < n ;i++){
            int l=segments[i][0];
            int r=segments[i][1];
            int val=segments[i][2] ;
            diff[l]+=val;
            diff[r]-=val;
        }

        for(int i = minend ;i < maxend+2 ;i++){
            diff[i]+=diff[i-1] ;
        }
        int p1=minend;
        for(int i = minend ; i<=maxend;i++){
            
            if(diff[i]==0){
                p1=i+1;
                continue ;
            }
            if(i>p1 && diff[i]==diff[i-1] && s.find(i)!=s.end()){
                ans.push_back({p1,i,diff[i]});
                p1=i;
            }
            if(diff[i]!=diff[i+1]){
                ans.push_back({p1,i+1,diff[i]}) ;
                p1=i+1;
            }

            if(i==maxend){
                break ; 
            }
        }

        return ans ;
    }
};