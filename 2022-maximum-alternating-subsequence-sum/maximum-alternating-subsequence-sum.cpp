class Solution {
public:
    long long fun(int idx,vector<int>& nums,int state,vector<vector<long long>>&dp){
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx][state]!=-1){
            return dp[idx][state];
        }
        long long ans;
        if(state){
            long long even=nums[idx]+fun(idx+1,nums,0,dp);
            long long skip=fun(idx+1,nums,state,dp);
            ans=max(even,skip);
        }else{
            long long odd=fun(idx+1,nums,1,dp)-nums[idx];
            long long skip=fun(idx+1,nums,state,dp);
            ans=max(odd,skip);
        }
        return dp[idx][state]=ans;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>>dp(nums.size(),vector<long long>(2,-1));
        return fun(0,nums,1,dp);
    }
};