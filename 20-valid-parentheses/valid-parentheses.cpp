class Solution {
public:
    bool isValid(string s) {
        int i,a=0,b=0,c=0;
        stack<char>st;
        for(i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                    st.push(s[i]);
            }
            else if(s[i]==')'&&!st.empty()&&st.top()=='('){
                st.pop();
            }
            else if(s[i]=='}'&&!st.empty()&&st.top()=='{'){
                st.pop();
            }
            else if(s[i]==']'&&!st.empty()&&st.top()=='['){
                st.pop();
            }
            else{
                c=1;
                break;
            }
        }
        if(!st.empty()||c==1)
            return false;
        else
            return true;
    }
};