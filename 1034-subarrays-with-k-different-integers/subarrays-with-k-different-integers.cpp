class Solution {
public:
    int ans(vector<int>&nums,int k){
        int l=0;
        unordered_map<int,int>m;
        int ans=0;
        for(int r=0;r<nums.size();r++){
            m[nums[r]]++;
            while(m.size()>k){
                m[nums[l]]--;
                if(m[nums[l]]==0){
                    m.erase(nums[l]);
                }
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (ans(nums,k)-ans(nums,k-1));
    }
};