class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int l=0,r=0,max_len=0;
        while(r<nums.size()){
            m[nums[r]]++;
            if(m[nums[r]]<=k){
                max_len=max(max_len,r-l+1);
            }else{
                while(l<=r){
                    if(m[nums[r]]<=k){
                        break;
                    }
                    m[nums[l]]--;
                    l++;
                    if(m[nums[l]]==0){
                        m.erase(nums[l]);
                    }
                }
                if(m[nums[r]]<=k){
                max_len=max(max_len,r-l+1);
                }
            }
            r++;
        }
        return max_len;
    }
};