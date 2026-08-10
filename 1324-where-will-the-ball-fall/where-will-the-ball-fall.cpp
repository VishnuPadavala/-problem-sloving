class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid[0].size(),m=grid.size();
        vector<int>ans(n,-1);
        for(int k=0;k<n;k++){
            ans[k]=fun(0,k,n,m,grid);
        }
        return ans;
    }
    int fun(int i,int j,int n,int m,vector<vector<int>>& grid){
        if(i<0 || j<0 ||i>m ||j>=n)return -1;
        if(i==m){
            return j;
        }
        if(grid[i][j]==1){
            if(j+1<n && grid[i][j+1]==1){
                return fun(i+1,j+1,n,m,grid);
            }
            else{
                return -1;
            }
        }
        else{
            if(j-1>=0 && grid[i][j-1]==-1){
                return fun(i+1,j-1,n,m,grid);
            }else{
                return -1;
            }
        }
    }
};