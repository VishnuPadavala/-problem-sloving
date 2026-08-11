class Solution {
public:
    int missingInteger(vector<int>& nums) {
        map<int,int>m;
        for(int num:nums){
            m[num]++;
        }
        int presum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                presum+=nums[i];
            }else{
                break;
            }
        }
        while(presum<=2500){
            if(!m.count(presum)){
                break;
            }
            presum++;
        }
        return presum;
    }
};