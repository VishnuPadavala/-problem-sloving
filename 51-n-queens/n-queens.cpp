class Solution {
public:
    vector<vector<string>>ans;
    vector<int>dx={-1,-1,-1},dy={-1,0,1};
    bool is_safe(int row,int col,vector<string>&board,int n){
        for(int k=0;k<3;k++){
            int dr=row+dx[k];
            int dc=col+dy[k];
            while(dr>=0 && dc>=0 && dr<n && dc<n){
                if(board[dr][dc]=='Q'){
                    return false;
                }
                dr+=dx[k];
                dc+=dy[k];
            }
        }
        return true;
    }
    void fun(int row,int n,vector<string>&board){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(is_safe(row,col,board,n)){
                board[row][col]='Q';
                fun(row+1,n,board);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        fun(0,n,board);
        return ans;
    }
};