class Solution {
public:
    vector<int>dx={0,0,-1,1},dy={-1,1,0,0};
    bool fun(int row,int col,int idx,const vector<vector<char>>& board,string word,vector<vector<bool>>&visit){
        if(idx==word.size()){
            return true;
        }
        int n=board.size(),m=board[0].size();
        bool b=false;
        for(int k=0;k<4;k++){
            int nrow=row+dx[k];
            int ncol=col+dy[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                if(!visit[nrow][ncol] && word[idx]==board[nrow][ncol]){
                    visit[nrow][ncol]=true;
                    b|=fun(nrow,ncol,idx+1,board,word,visit);
                    visit[nrow][ncol]=false;
                }
            }
        }
        return b;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        vector<vector<bool>>visit(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    visit[i][j]=true;
                    if(fun(i,j,1,board,word,visit)){
                        return true;
                    }
                    visit[i][j]=false;
                }
            }
        }
        return false;
    }
};