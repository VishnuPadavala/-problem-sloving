class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        stack<char>st;
        string s1="";
        string ans="";
        map<string,string>m;
        for(auto e:k){
            m[e[0]]=e[1];
        }
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                if(s[i]=='('){
                    st.push(s[i]);
                }else{
                    ans+=s[i];
                }
            }else{
                if(st.top()=='('){
                    if(s[i]==')'){
                        if(m.find(s1)!=m.end()){
                            ans+=m[s1];
                        }else{
                            ans+='?';
                        }
                        s1="";
                        st.pop();
                    }else{
                        s1+=s[i];
                    }
                }
            }
        }
        return ans;
    }
};