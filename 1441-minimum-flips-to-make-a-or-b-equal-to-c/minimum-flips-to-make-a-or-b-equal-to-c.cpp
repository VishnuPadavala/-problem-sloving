class Solution {
public:
    int minFlips(int a, int b, int c) {
        bitset<32>a1(a),b1(b),c1(c);
        int count=0;
        for(int i=0;i<32;i++){
            if(!(a1[i]+b1[i]) && c1[i]){
                count++;
            }else if((a1[i]+b1[i]) && !c1[i]){
                if(a1[i] && b1[i])
                    count+=2;
                else
                    count++;
            }
        }
        return count;
    }
};