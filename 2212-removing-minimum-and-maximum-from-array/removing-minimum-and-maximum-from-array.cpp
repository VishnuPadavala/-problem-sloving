class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int max_idx=-1,min_idx=-1,max_ele=-1e5,min_ele=1e5;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(max_ele < nums[i]){
                max_ele=nums[i];
                max_idx=i;
            }
            if(min_ele > nums[i]){
                min_ele=nums[i];
                min_idx=i;
            }
        }
        int ans=INT_MAX;
        ans=min(ans,max(max_idx,min_idx)+1);
        ans=min(ans,n-min(max_idx,min_idx));
        ans=min(ans,min(max_idx,min_idx)+1+(n-max(max_idx,min_idx)));
        return ans;
    }
};