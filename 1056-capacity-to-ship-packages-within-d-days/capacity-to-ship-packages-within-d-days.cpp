class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=0,r=0;
        for(int w:weights){
            l=max(w,l);
            r+=w;
        }
        int res=r;
        while(l<r){
            int mid=(l+r)/2;
            if(check(weights,days,mid)){
                res=mid;
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
    bool check(vector<int>&nums,int d,int mid){
        int c=0,sum=0,i=0;
        while(i<nums.size()){
            if(sum+nums[i] > mid){
                c++;
                sum=0;
            }
            sum+=nums[i];
            i++;
            if(c>d)return false;
        }
        return c<=d-1;
    }
};