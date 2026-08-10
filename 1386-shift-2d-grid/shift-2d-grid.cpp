class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>>nums(grid.size(),(vector<int>(grid[0].size())));
        int n=grid.size(),m=grid[0].size();
        while(k--){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(j==m-1){
                        if(i==n-1){
                            nums[0][0]=grid[i][j];
                        }else{
                            nums[i+1][0]=grid[i][j];
                        }
                    }else{
                        nums[i][j+1]=grid[i][j];
                    }
                }
            }
            grid=nums;
        }
        return grid;
    }
};