class Solution {
public:
    vector<int>dx={0,-1,0,1},dy={-1,0,1,0};
    void fun(vector<vector<char>>& grid ,int i,int j,vector<vector<bool>>&visit){
        visit[i][j]=true;
        int n=grid.size();
        int m=grid[0].size();
        for(int k=0;k<4;k++){
            int r=i+dx[k];
            int c=j+dy[k];
            if(r>=0 && c>=0 &&r<n && c<m && grid[r][c]=='1'){
                if(!visit[r][c]){
                    fun(grid,r,c,visit);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        vector<vector<bool>>visit(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visit[i][j]){
                    ans++;
                    fun(grid,i,j,visit);
                }
            }
        }
        return ans;
    }
};