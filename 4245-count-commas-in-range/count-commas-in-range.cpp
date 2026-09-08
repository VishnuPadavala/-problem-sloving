class Solution {
public:
    int countCommas(int n) {
        long long p=1000;
        int ans=0;
        while(n>=p){
            ans+=(n-p+1);
            p*=1000;
        }
        return ans;
    }
};