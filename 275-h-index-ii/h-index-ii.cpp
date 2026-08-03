class Solution {
public:
    int hIndex(vector<int>& nums) {
        if(nums.size()==1){
            if(1<=nums[0]){
                return 1;
            }else{
                return 0;
            }
        }
        int n=nums.size(),ele=0;
        sort(nums.rbegin(),nums.rend());
        int l=0,h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]>=mid+1){
                l=mid+1;
                ele=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ele;
    }
};