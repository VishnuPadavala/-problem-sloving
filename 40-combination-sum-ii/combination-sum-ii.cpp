class Solution {
public:
    vector<vector<int>>ans;
    void fun(vector<int>&c,int idx,vector<int>&nums,int target){
        if(target==0){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<c.size();i++){
            if(i>idx && c[i]==c[i-1])continue;
            if(c[i]<=target){
                nums.push_back(c[i]);
                fun(c,i+1,nums,target-c[i]);
                nums.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<int>nums;
        sort(c.begin(),c.end());
        fun(c,0,nums,target);
        return ans;
    }
};