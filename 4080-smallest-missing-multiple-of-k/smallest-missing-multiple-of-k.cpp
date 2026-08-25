class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=k;
        while(find(nums.begin(),nums.end(),n)!=nums.end()){
            n+=k;
        }
        return n;
    }
};