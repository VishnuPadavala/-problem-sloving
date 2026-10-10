class Solution {
public:
    long long fun(vector<int>& coins,int amount,vector<long long>&dp){
        if(amount<0){
            return 1e5;
        }
        if(amount==0){
            return 0;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        long long ans=1e5;
        for(int i=0;i<coins.size();i++){
            ans=min(ans,1+fun(coins,amount-coins[i],dp));
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<long long>dp(amount+1,-1);
        int ans=(int)fun(coins,amount,dp);
        return ans==1e5?-1:ans;
    }
};