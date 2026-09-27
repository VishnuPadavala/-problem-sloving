class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty()){
                if(s[i]==')'){
                    string s1="";
                    while(!st.empty() && st.top()!='('){
                        s1.push_back(st.top());
                        st.pop();
                    }
                    if(!st.empty())
                        st.pop();
                    for(int k=0;k<s1.size();k++){
                        st.push(s1[k]);
                    }
                }
                else{
                    st.push(s[i]);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string s1="";
        while(!st.empty()){
            s1+=st.top();
            st.pop();
        }
        reverse(s1.begin(),s1.end());
        return s1;
    }
};