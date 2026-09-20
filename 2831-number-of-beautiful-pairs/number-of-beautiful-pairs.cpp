class Solution {
public:
    int gcd(int a,int b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    bool coprimes(int a,int b){
        int ans;
        if(a>b)
        ans=gcd(a,b);
        else
        ans=gcd(b,a);
        return ans==1;
    }
    int countBeautifulPairs(vector<int>& nums) {
        int n=nums.size();
        vector<int>last,first;
        for(int num:nums){
            int no=num;
            int r;
            last.push_back(no%10);
            while(no>0){
                r=no%10;
                no/=10;
            }
            first.push_back(r);
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(coprimes(first[i],last[j])){
                    count++;
                }
            }
        }
        return count;
    }
};