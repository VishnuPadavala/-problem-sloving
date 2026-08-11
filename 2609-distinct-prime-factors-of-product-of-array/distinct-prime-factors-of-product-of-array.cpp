class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int max_val=0;
        for(int num:nums){
            max_val=max(max_val,num);
        }
        vector<int>v(max_val+1);
        for(int i=0;i<=max_val;i++){
            v[i]=i;
        }
        for(int i=2;i*i<=max_val;i++){
            if(v[i]!=i){
                continue;
            }
            for(int j=i*i;j<=max_val;j+=i){
                if(v[j]==j)
                    v[j]=i;
            }
        }
        unordered_set<int>s;
        for(int num:nums){
            int n=num;
            while(n>1){
                s.insert(v[n]);
                n/=v[n];
            }
        }
        return s.size();
    }
};