class Solution {
public:
    vector<int>dx={-1,0,0,1},dy={0,1,-1,0};
int fun(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<bool>>&visit){
        visit[i][j]=true;
        int Area=1;
        for(int k=0;k<4;k++){
            int r=i+dx[k];
            int c=j+dy[k];
            if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1){
                if(!visit[r][c]){
                    Area+=fun(grid,r,c,n,m,visit);
                }
            }
        }
        return Area;
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>visit(n,vector<bool>(m,false));
        int ans=4;
        int max_val=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visit[i][j]){
                    max_val=max(max_val,fun(grid,i,j,n,m,visit));
                }
            }
        }
        return max_val;
    }
};