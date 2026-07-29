class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int>m;
        for(char ch:s){
            m[ch]++;
        }
        string s1="",s2;
        for(auto &p:m){
            for(int i=1;i<=p.second/2;i++){
                s1+=p.first;
            }
        }
        s2=s1;
        reverse(s2.begin(),s2.end());
        cout<<s2;
        for(auto &p:m){
            if(p.second%2!=0)
            s1+=p.first;
        }
        return s1+s2;
    }
};