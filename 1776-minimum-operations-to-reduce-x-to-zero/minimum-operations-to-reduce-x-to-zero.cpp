class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int count=0;
        int size=-1;
        int left=0;
        int totalsum=0;
        for(int num:nums){
            totalsum+=num;
        }
        int target=totalsum-x;
        int sum=0;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while(left<=right && sum > target){
                sum-=nums[left++];
            }
            if(sum==target){
                size=max(size,right-left+1);
            }
        }
        return size==-1?-1:nums.size()-size;
    }
};