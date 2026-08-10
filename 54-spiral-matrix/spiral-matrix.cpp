class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int r=matrix.size(),c=matrix[0].size();
        int i=0,j=0;
        while(r>0 && c>0){
            if(r==1 || c==1){
                break;
            }
            for(int k=0;k<c-1;k++){
                ans.push_back(matrix[i][j]);
                j++;
            }
            for(int k=0;k<r-1;k++){
                ans.push_back(matrix[i][j]);
                i++;
            }
            for(int k=0;k<c-1;k++){
                ans.push_back(matrix[i][j]);
                j--;
            }
            for(int k=0;k<r-1;k++){
                ans.push_back(matrix[i][j]);
                i--;
            }
            i++;
            j++;
            r-=2;
            c-=2;
        }
        if(r==1){
            for(int k=0;k<c;k++){
                ans.push_back(matrix[i][j]);
                j++;
            }
        }else if(c==1){
            for(int k=0;k<r;k++){
                ans.push_back(matrix[i][j]);
                i++;
            }
        }
        return ans;
    }
};