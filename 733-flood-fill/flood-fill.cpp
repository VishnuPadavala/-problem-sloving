class Solution {
public:
    vector<int>dx={0,0,1,-1},dy={-1,1,0,0};
    void fun(vector<vector<int>>&image,int i,int j,int color,int t,vector<vector<bool>>&visit){
        visit[i][j]=true;
        image[i][j]=color;
        int n=image.size(),m=image[0].size();
        for(int k=0;k<4;k++){
            int r=i+dx[k];
            int c=j+dy[k];
            if(r>=0 && c>=0 && r<n && c<m && image[r][c]==t){
                 image[r][c]=color;
                 fun(image,r,c,color,t,visit);
            }
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int target=image[sr][sc];
        int n=image.size(),m=image[0].size();
        if(target==color)return image;
        vector<vector<bool>>visit(n,vector<bool>(m,false));
        fun(image,sr,sc,color,target,visit);
        return image;
    }
};