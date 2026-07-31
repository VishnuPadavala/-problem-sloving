class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>m;
        for(char ch:word){
            m[ch]++;
        }
        vector<int>nums;
        for(auto &p:m){
            nums.push_back(p.second);
        }
        sort(nums.rbegin(),nums.rend());
        cout<<nums.size();
        int k=1,c=1,count=0;
        for(int num:nums){
           if(k==9){
                c++;
                k=1;
                count+=c*num;
           }else{
            count+=c*num;
           }
           k++;
        }
        return count;
    }
};