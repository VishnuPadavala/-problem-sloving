class Solution {
public:
    int reverseDegree(string s) {
        char ch='a';
        map<char,int>m;
        for(int i=26;i>=0;i--){
            m[ch]=i;
            ch++;
        }
        int sum=0;
        for(int i=0;i<s.size();i++){
            sum+=m[s[i]]*(i+1);
        }
        return sum;
    }
};