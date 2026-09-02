class primetable{
    private:
        vector<int>primenumber;
        int n=5e6+1;
    public:
    primetable(){
        vector<bool>prime(n,true);
        prime[0]=prime[1]=false;
        for(int i=2;i*i<n;i++){
            if(!prime[i]){
                continue;
            }
            for(int j=i*i;j<n;j+=i){
                prime[j]=false;
            }
        }
        for(int i=2;i<n;i++){
            if(prime[i]){
                primenumber.push_back(i);
            }
        }
        cout<<"vishnu";
        return;
    }
    int countprime(int ele){
        auto it=lower_bound(primenumber.begin(),primenumber.end(),ele);
        return it-primenumber.begin();
    }
};

primetable p;
class Solution {
public:
    int countPrimes(int n) {
        return p.countprime(n);
    }
};