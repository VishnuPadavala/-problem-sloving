class Solution {
public:
    bool prime(long long n){
        if(n==1){
            return false;
        }
        for(long long i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    bool palindrome(long long n){
        long long original=n;
        long long sum=0;
        while(n>0){
            sum=(sum*10)+(n%10);
            n/=10;
        }
        return original==sum;
    }
    int primePalindrome(int n) {
        int num=n;
        while(true){
            if(1e7<=num && num<=1e8){
                num=1e8;
            }
            if(prime((long long)num) && palindrome((long long)num)){
                return num;
            }
            num++;
        }
        return 0;
    }
};