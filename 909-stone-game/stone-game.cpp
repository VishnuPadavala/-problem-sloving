class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int l=0,r=piles.size()-1,sum1=0,sum2=0,trun=0;
        vector<vector<int>>dp(r+1,vector<int>(r+1,-1));
        bool b=Gamestone(piles,l,r,sum1,sum2,trun,dp);
        return b;
    }
    bool Gamestone(vector<int>&nums,int l,int r,int sum1,int sum2,int trun,vector<vector<int>>&dp){
        if(l>r){
            if(sum1>sum2){
                return true;
            }else{
                return false;
            }
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        bool b1=false,b2=false;
            if(trun==0){
                b1=Gamestone(nums,l+1,r,sum1+nums[l],sum2,1,dp);
                b2=Gamestone(nums,l,r-1,sum1+nums[r],sum2,1,dp);
            }
            else{
                b1=Gamestone(nums,l+1,r,sum1,sum2+nums[l],0,dp);
                b2=Gamestone(nums,l,r-1,sum1,sum2+nums[r],0,dp);
            }
        return dp[l][r]=b1 | b2;
    }
};