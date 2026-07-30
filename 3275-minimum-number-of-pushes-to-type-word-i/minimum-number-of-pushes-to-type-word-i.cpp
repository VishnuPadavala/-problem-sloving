class Solution {
public:
    int minimumPushes(string word) {
        int k=1,c=1,count=0;
        for(int i=0;i<word.size();i++){
            if(k==9){
                k=2;
                c++;
                count+=c;
            }
            else{
                count+=c;
                k++;
            }
        }
        return count;
    }
};