class Solution {
public:
    bool fun(int idx,int open,string s,vector<vector<int>>&dp){
        if(open<0){
            return false;
        }
        if(idx==s.size()){
            return open==0;
        }
        if(dp[idx][open]!=-1){
            return dp[idx][open];
        }
        bool ans=false;
        if(s[idx]=='('){
            ans=fun(idx+1,open+1,s,dp);
        }else if(s[idx]==')'){
            ans=fun(idx+1,open-1,s,dp);
        }       
        else{
            ans|=fun(idx+1,open+1,s,dp);
            ans|=fun(idx+1,open,s,dp);
            ans|=fun(idx+1,open-1,s,dp);
        }
        return dp[idx][open]=ans;
    }
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return fun(0,0,s,dp);
    }
};