class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int total=0;
        for(int i=0;i<pow(2,(nums.size()));i++){
            int sum=0;
            for(int j=0;j<nums.size();j++){
                if(((1<<j)&i) != 0){
                    sum^=nums[j];
                }
            }
            total+=sum;
        }
        return total;
    }
};