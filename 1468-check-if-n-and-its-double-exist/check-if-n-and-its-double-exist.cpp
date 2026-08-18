class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>m;
        for(int num:arr){
            m[num]++;
        }
        for(int num:arr){
            if(num==0){
                if(m[num]>1){
                    return true;
                }
            }
            if(num!=0 && m[2*num]>0){
                return true;
            }
        }
        return false;
    }
};