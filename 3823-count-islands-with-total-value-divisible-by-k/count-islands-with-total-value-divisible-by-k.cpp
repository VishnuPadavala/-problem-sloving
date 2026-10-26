class Solution {
public:
    vector<int>dx={0,-1,0,1},dy={-1,0,1,0};
    long long fun(vector<vector<int>>& grid ,int i,int j,vector<vector<bool>>&visit){
        visit[i][j]=true;
        long long sum=grid[i][j];
        int n=grid.size();
        int m=grid[0].size();
        for(int k=0;k<4;k++){
            int r=i+dx[k];
            int c=j+dy[k];
            if(r>=0 && c>=0 &&r<n && c<m && grid[r][c]!=0){
                if(!visit[r][c]){
                    sum+=fun(grid,r,c,visit);
                }
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        vector<vector<bool>>visit(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0 && !visit[i][j]){
                    long long sum=fun(grid,i,j,visit);
                    if(sum%k==0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};