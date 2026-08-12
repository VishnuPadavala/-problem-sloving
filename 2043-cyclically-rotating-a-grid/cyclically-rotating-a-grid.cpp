class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>>nums;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>ans=grid;
        int i=0,j=0;
        vector<int>a;
        while(n>0 && m>0){
            for(int k=0;k<m-1;k++){
                a.push_back(grid[i][j]);
                j++;
            }
            for(int k=0;k<n-1;k++){
                a.push_back(grid[i][j]);
                i++;
            }
            for(int k=m;k>1;k--){
                a.push_back(grid[i][j]);
                j--;
            }
            for(int k=n;k>1;k--){
                a.push_back(grid[i][j]);
                i--;
            }
            cout<<i<<" "<<j<<endl;
            int sz=a.size();
            int start=k%sz;
            int idx=start;
            for(int k=0;k<m-1;k++){
                grid[i][j]=a[idx++];
                if(idx==sz){
                    idx=0;
                }
                j++;
            }
            for(int k=0;k<n-1;k++){
                grid[i][j]=a[idx++];
                if(idx==sz){
                    idx=0;
                }
                i++;
            }
            for(int k=m;k>1;k--){
                grid[i][j]=a[idx++];
                if(idx==sz){
                    idx=0;
                }
                j--;
            }
            for(int k=n;k>1;k--){
                grid[i][j]=a[idx++];
                if(idx==sz){
                    idx=0;
                }
                i--;
            }
            i++;
            j++;
            n-=2;
            m-=2;
            a.clear();
        }
        return grid;
    }
};