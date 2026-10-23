class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int>notequal;
        int max_and=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                max_and&=nums[i];
            }
        }
        return max_and==-1?0:max_and;
    }
};