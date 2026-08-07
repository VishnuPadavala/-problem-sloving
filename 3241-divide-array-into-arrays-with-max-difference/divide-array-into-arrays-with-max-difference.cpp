class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n%3!=0){
            return ans;
        }
        for(int i=0;i<n;i=i+3){
            if(abs(nums[i]-nums[i+1])<=k && abs(nums[i]-nums[i+2])<=k && abs(nums[i+1]-nums[i+1])<=k){
                ans.push_back({nums[i],nums[i+1],nums[i+2]});
            }else{
                return {};
            }
        }
        return ans;
    }
};