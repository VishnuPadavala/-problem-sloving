class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>v(matrix.size(),vector<int>(matrix.size(), 0));
        int k=0,o=0;
        for(int j=0;j<matrix.size();j++,k++){
            o=0;
            for(int i=matrix.size()-1;i>=0;i--,o++){
                v.at(k).at(o)=matrix[i][j];
            }
        }
        matrix=v;
    }
};