class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>>nums(matrix[0].size(),vector<int>(matrix.size(),0));
        for(int j=0;j<matrix[0].size();j++){
            for(int i=0;i<matrix.size();i++){
                nums[j][i]=matrix[i][j];
            }
        }
        return nums;
    }
};