class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        num-=3;
        if(num%3==0){
            long long n=num/3;
            return {n,n+1,n+2};
        }
        return {};
    }
};