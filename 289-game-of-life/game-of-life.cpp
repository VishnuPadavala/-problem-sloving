class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>>index={
            {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}
        };
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ele=board[i][j];
                int sum=0;
                for(auto e:index){
                    int nr=i+e[0];
                    int nc=j+e[1];
                    if(nr>=0 && nr<n && nc>=0 && nc<m){
                        sum+=board[nr][nc];
                    }
                }
                if(ele==1 && sum<2){
                    ans[i][j]=0;
                }else if(ele==1 && sum==2){
                    ans[i][j]=1;
                }else if(ele==1 && sum==3){
                    ans[i][j]=1;
                }else if(ele==1 && sum>3){
                    ans[i][j]=0;
                }else if(ele==0 && sum==3){
                    ans[i][j]=1;
                }else{
                    ans[i][j]=0;
                }
            }
        }
        board=ans;
    }
};