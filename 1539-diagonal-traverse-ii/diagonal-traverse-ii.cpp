class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                m[i+j].push_back(nums[i][j]);
            }
        }
        vector<int>ans;
        for(auto &p:m){
            vector<int>v=p.second;
            for(int i=v.size()-1;i>=0;i--){
                ans.push_back(v[i]);
            }
        }
        return ans;
    }
};