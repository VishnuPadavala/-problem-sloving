class Solution {
public:
    vector<int>dx={0,0,-1,1,-1,-1,1,1},dy={1,-1,0,0,1,-1,-1,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;
        vector<vector<bool>>visit(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        q.push({0,0});
        visit[0][0]=true;
        int count=1;
        int main=0;
        visit[0][0]=true;
        while(!q.empty()){
            int size=q.size();
            int f=0;
            for(int i=0;i<size;i++){
                int r=q.front().first;
                int c=q.front().second;
                if(r==n-1 && c==m-1){
                    f=1;
                    break;
                }
                q.pop();
                int f=1;
                for(int k=0;k<8;k++){
                    int r1=r+dx[k];
                    int c1=c+dy[k];
                    if(r1>=0 && c1>=0 && r1<n && c1<m && grid[r1][c1]==0 && !visit[r1][c1]){
                        visit[r1][c1]=true;
                        q.push({r1,c1});
                    }
                }
            }
            if(f==1){
                main=1;
                break;
            }
            count++;
        }
        if(main==1)return count;
        return -1;
    }
};