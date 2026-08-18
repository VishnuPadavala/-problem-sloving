class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long mod=1e9+7;
        int odd=0,even=0;
        long long presum=0;
        long long count=0;
        for(int i=0;i<arr.size();i++){
            presum=(presum+arr[i]);
            if(presum%2==0){
                count=(count+odd)%mod;
                even++;
            }else{
                count=(count+1)%mod;
                count=(count+even)%mod;
                odd++;
            }
        }
        return count;
    }
};