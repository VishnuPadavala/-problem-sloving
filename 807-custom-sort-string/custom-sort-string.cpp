class Solution {
public:
    string customSortString(string order, string s) {
        string s1="",ans="";
        unordered_map<char,int>m;
        vector<int>v(order.size()+1,0);
        int c=1;
        for(char ch:order){
            m[ch]=c++;
        }
        for(char ch:s){
            if(m[ch]==0){
                s1+=ch;
            }else{
                v[m[ch]]++;
            }
        }
        for(int i=1;i<v.size();i++){
            for(int j=0;j<v[i];j++){
                ans+=order[i-1];
            }
        }
        return ans+s1;
    }
};