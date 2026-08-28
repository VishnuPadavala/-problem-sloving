class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int xor_val=0;
        for(int i:nums){
            xor_val^=i;
        }
        long long int diff=((xor_val)&(-xor_val));
        int a1=0,a2=0;
        for(long long int i:nums){
            if(i&diff){
                a1^=i;
            }
            else{
                a2^=i;
            }
        }
        return {a1,a2};
    }
};