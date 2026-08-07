class Solution {
public:
    vector<int>dx={0,0,-1,1},dy={-1,1,0,0};
    queue<pair<int,int>>q;
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>visit(n,vector<bool>(m,false));
        int count=0,ones=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    ones++;
                }
            }
        }
         while(!q.empty()){
            int size=q.size();
            int f=0;
            for(int k=0;k<size;k++){
                int r=q.front().first;
                int c=q.front().second;
                visit[r][c]=true;
                q.pop();
                for(int l=0;l<4;l++){
                    int r1=r+dx[l];
                    int c1=c+dy[l];
                    if(r1>=0 && c1>=0 && r1<n && c1<m && grid[r1][c1]==1){
                        ones--;
                        grid[r1][c1]=2;
                        q.push({r1,c1});
                        f=1;
                    }
                }
            }
            if(f==1){
                count++;
            }
        }
        if(ones>0)return -1;
        return count;
    }
};