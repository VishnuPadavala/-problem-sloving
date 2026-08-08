class Solution {
public:
    vector<int>dx={0,0,-1,1},dy={-1,1,0,0};
    int dfs(vector<vector<int>>& grid,int i,int j,bool &b,vector<vector<bool>>& visit){
        int n=grid.size(),m=grid[0].size();
        visit[i][j]=true;
        if(i-1<0 || j-1<0 || j+1>=m || i+1>=n){
            b=false;
        }
        int count=1;
        for(int k=0;k<4;k++){
            int r=i+dx[k];
            int c=j+dy[k];
            if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==1 && !visit[r][c]){
                count+=dfs(grid,r,c,b,visit);
            }
        }
        return count;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>visit(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visit[i][j]){
                    bool b=true;
                    int sz=dfs(grid,i,j,b,visit);
                    if(b){
                        ans+=sz;
                    }
                }
            }
        }
        return ans;
    }
};