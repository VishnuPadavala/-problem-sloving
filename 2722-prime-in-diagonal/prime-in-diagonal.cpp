class Solution {
public:
    bool prime(int num){
        if(num==1){
            return false;
        }
        for(int i=2;i*i<=num;i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n=nums.size(),m=nums[0].size();
        vector<int>a;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==j){
                    a.push_back(nums[i][j]);
                }else if(i+j==n-1){
                    a.push_back(nums[i][j]);
                }
            }
        }
        sort(a.begin(),a.end());
        for(int i=a.size()-1;i>=0;i--){
            if(prime(a[i])){
                return a[i];
            }
        }
        return 0;
    }
};