class Solution {
public:
    long long fun(long long n,long long count){
        long long sum=1,c=n;
        long long mod=1e9+7;
        while(count>0){
            if(count&1){
                sum=(sum*c)%mod;
            }
            c=(c*c)%mod;
            count >>= 1;
        }
        return sum;
    }
    int countGoodNumbers(long long n) {
        long long sum=1;
        long long mod=1e9+7;
        long long even=(n+1)/2,odd=n/2;
        sum=fun(5,even)%mod;
        sum=(sum*(fun(4,odd))%mod)%mod;
        return sum;
    }
};