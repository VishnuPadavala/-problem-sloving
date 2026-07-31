class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int e) {
        sort(piles.begin(),piles.end());
        int l=1,res=0;
        int h=piles.back();
        while(l<=h){
            int mid=(l+h)/2;
            if(check(piles,e,mid)){
                res=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
    bool check(vector<int>&nums,int h,int mid){
        int c=0,i=0;
        while(i<nums.size()){
            c+=(nums[i]+mid-1)/mid;
            i++;
            if(c>h)return false;
        }
        return c<=h && i==nums.size();
    }
};