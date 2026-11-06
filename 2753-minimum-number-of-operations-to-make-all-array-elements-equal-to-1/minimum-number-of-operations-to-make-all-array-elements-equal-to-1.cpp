class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int found=0,second=0;
        int prev=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }
        }
        if(count>0){
            return nums.size()-count;
        }
        int min_len=INT_MAX;
        for(int i=0;i<n;i++){
            int g=nums[i];
            for(int j=i+1;j<n;j++){
                g=__gcd(g,nums[j]);
                if(g==1){
                    min_len=min(min_len,j-i+1);
                    break;
                }
            }
        }
        if(min_len==INT_MAX){
            return -1;
        }
        return n+min_len-2;
    }
};