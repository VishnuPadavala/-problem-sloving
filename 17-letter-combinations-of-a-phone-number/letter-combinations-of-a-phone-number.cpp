class Solution {
public:
    void fun(int i,string s,string digits,unordered_map<int,string>&m,vector<string>&ans){
        if(i==digits.size()){
            ans.push_back(s);
            return;
        }
        for(auto a : m[digits[i]-'0']){
            s.push_back(a);
            fun(i+1,s,digits,m,ans);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n=digits.size(),i=0,num,k;
        vector<string>ans;
        unordered_map<int,string>m{
            {2,"abc"},
            {3,"def"},
            {4,"ghi"},
            {5,"jkl"},
            {6,"mno"},
            {7,"pqrs"},
            {8,"tuv"},
            {9,"wxyz"}
        };
        string s="";
        fun(0,s,digits,m,ans);
        return ans;
    }
};