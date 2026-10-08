class Solution {
public:
    int fun(int idx,vector<int>& prices,int state,vector<vector<int>>&dp){
        if(idx>=prices.size()){
            return 0;
        }
        if(dp[idx][state]!=-1){
            return dp[idx][state];
        }
        int ans;
        if(state==0){
            int buy=fun(idx+1,prices,1,dp)-prices[idx];
            int skip=fun(idx+1,prices,0,dp);
            ans=max(buy,skip);
        }else{
            int sell=prices[idx]+fun(idx+2,prices,0,dp);
            int hold=fun(idx+1,prices,1,dp);
            ans=max(sell,hold);
        }
        return dp[idx][state]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int total=0;
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return fun(0,prices,0,dp);
    }
};