class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        map<int,vector<int>>m1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                m1[i+j].push_back(mat[i][j]);
            }
        }
        vector<int>ans;
        vector<int>oa=m1[0];
        ans.insert(ans.end(),oa.begin(),oa.end());
        int f=0;
        for(int i=1;i<=(n+m-2);i++){
            oa=m1[i];
            if(f==0){
                ans.insert(ans.end(),oa.begin(),oa.end());
                f=1;
            }else{
                reverse(oa.begin(),oa.end());
                ans.insert(ans.end(),oa.begin(),oa.end());
                f=0;
            }
        }
        return ans;
    }
};