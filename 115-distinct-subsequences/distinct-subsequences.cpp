class Solution {
int fun(string &s, string &t,int idx1,int idx2,vector<vector<int>>&dp){
    if(idx2>=t.size()){
        return 1;
    }
    if(idx1>=s.size()){
        return 0;
    }
    if(dp[idx1][idx2]!=-1){
        return dp[idx1][idx2];
    }
    int ways=fun(s,t,idx1+1,idx2,dp);
    if(s[idx1]==t[idx2]){
        ways+=fun(s,t,idx1+1,idx2+1,dp);
    }
    return dp[idx1][idx2]=ways;
}
public:
    int numDistinct(string s, string t) {
        int n1=s.size(),n2=t.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return fun(s,t,0,0,dp);
    }
};