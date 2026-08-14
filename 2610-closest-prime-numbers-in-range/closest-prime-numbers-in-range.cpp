class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n=right;
        vector<int>nums(n+1,1);
        nums[0]=nums[1]=0;
        for(int i=2;i*i<=n;i++){
            if(!nums[i]){
                continue;
            }
            for(int j=i*i;j<=n;j+=i){
                nums[j]=0;
            }
        }
        vector<int>inter;
        for(int i=left;i<=right;i++){
            if(nums[i]){
                inter.push_back(i);
            }
        }
        int idx=-1,min_val=INT_MAX;
        for(int i=1;i<inter.size();i++){
            if(min_val>(inter[i]-inter[i-1])){
                idx=i-1;
                min_val=inter[i]-inter[i-1];
            }
        }
        if(idx==-1){
            return {-1,-1};
        }
        return {inter[idx],inter[idx+1]};
    }
};