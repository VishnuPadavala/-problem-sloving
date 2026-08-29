class Solution {
public:
    bool isHappy(int n) {
        unsigned int s,r,v;
        map<int,int>m;
            while(n!=1 && m[n]==0)
            {
                m[n]=1;
                s=0;
                while(n!=0)
                {
                    r=n%10;
                    v=pow(r,2);
                    s+=v;
                    n/=10;
                }
                n=s;
            }
            return n==1;
    }
};