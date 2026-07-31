class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long l=0,r=0;
        for(int num:nums){
            l=max(l,(long long)num);
            r+=(long long)num;
        }
        int res=r;
        while(l<r){
            long long mid=(l+r)/2;
            if(check(nums,k,(int)mid)){
                res=(int)mid;
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
    bool check(vector<int>&nums,int k,int mid){
        int cnt=1,sum=0;
        for(int num:nums){
            if(sum+num>mid){
                cnt++;
                sum=0;
            }
            sum+=num;
            if(cnt>k){
                return false;
            }
        }
        return cnt<=k;
    }
};