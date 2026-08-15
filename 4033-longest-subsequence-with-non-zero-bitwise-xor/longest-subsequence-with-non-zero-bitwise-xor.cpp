class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x_or=0,check=0;
        for(int num:nums){
            x_or^=num;
            check |= (num>0);
        }
        if(x_or!=0){
            return nums.size();
        }
        if(check){
            return nums.size()-1;
        }
        return 0;
    }
};