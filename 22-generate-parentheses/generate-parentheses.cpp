class Solution {
public:
    void fun(string &s,int open,int close,vector<string>&ans){
        if(open==0 && close==0){
            ans.push_back(s);
            return;
        }
        if(open==close){
            string s1=s;
            s1+="(";
            fun(s1,open-1,close,ans);
        }
        else if(open==0){
            string s2=s;
            s2+=")";
            fun(s2,open,close-1,ans);
        }else{
            string s2=s,s1=s;
            s1+="(";
            s2+=")";
            fun(s2,open,close-1,ans);
            fun(s1,open-1,close,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        int open=n,close=n;
        vector<string>ans;
        string s="";
        fun(s,open,close,ans);
        return ans;
    }
};