class Solution {
public:
    int fun(int i,vector<int>& prices,int states,int fee,vector<vector<int>>&dp){
        if(i>=prices.size()){
            return 0;
        }
        int ans;
        if(dp[i][states]!=-1){
            return dp[i][states];
        }
        if(states==0){
            int buy=fun(i+1,prices,1,fee,dp)-prices[i];
            int skip=fun(i+1,prices,0,fee,dp);
            ans=max(buy,skip);
        }else{
            int sell=fun(i+1,prices,0,fee,dp)+prices[i]-fee;
            int hold=fun(i+1,prices,1,fee,dp);
            ans=max(sell,hold);
        }
        return dp[i][states]=ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return fun(0,prices,0,fee,dp);
    }
};