class Solution {
public:
    int reverseBits(int n) {
        int sum=0;
        bitset<32>b(n);
        for(int i=0;i<32;i++)
        {
            if(b[i]==1)
            sum+=(1<<(31-i));
        }
        return sum;
    }
};