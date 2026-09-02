class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int max_val=0;
        for(int num:nums){
            max_val=max(max_val,num);
        }
        vector<bool>prime(max_val+1,true);
        prime[0]=prime[1]=false;
        for(int i=2;i*i<=max_val;i++){
            if(!prime[i]){
                continue;
            }
            for(int j=i*i;j<=max_val;j+=i){
                prime[j]=false;
            }
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(prime[nums[i]]){
                ans.push_back(i);
            }
        }
        return abs(ans.back()-ans[0]);
    }
};