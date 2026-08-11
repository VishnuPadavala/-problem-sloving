class Solution {
public:
    int smallestValue(int n) {
        vector<int>sfc(n+1);
        for(int i=0;i<=n;i++){
            sfc[i]=i;
        }
        for(int i=2;i*i<=n;i++){
            if(sfc[i]!=i){
                continue;
            }
            for(int j=i*i;j<=n;j+=i){
                if(sfc[j]==j){
                    sfc[j]=i;
                }
            }
        }
        int prev=0,f=0;
        while(sfc[n]!=n){
            int sum=0;
            while(sfc[n]!=n){
                sum+=sfc[n];
                n/=sfc[n];
            }
            sum+=sfc[n];
            n=sum;
            if(prev==sum){
                f=1;
                break;
            }
            prev=sum;
        }
        if(f==1){
            return n;
        }
        return n;
    }
};