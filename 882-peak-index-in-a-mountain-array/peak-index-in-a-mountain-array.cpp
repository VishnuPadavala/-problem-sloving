class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        int idx=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]>nums[mid+1]){
                idx=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return idx;
    }
};