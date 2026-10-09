class Solution {
public:
    int minInsertions(string s) {
        int i=0;
        stack<char>st;
        int c=0;
        while(i<s.size()){
            if(s[i]=='('){
                st.push(s[i]);
                i++;
            }else{
                if(i+1<s.size()){
                    if(s[i+1]==')' && !st.empty()){
                        st.pop();
                        i+=2;
                    }else if(s[i+1]==')' && st.empty()){
                        c++;
                        i+=2;
                    }else{
                        if(!st.empty()){
                            st.pop();
                            c++;
                        }
                        else{
                            c+=2;
                        }
                        i++;
                    }
                }else{
                    if(!st.empty()){
                        st.pop();
                        c++;
                    }else{
                        c+=2;
                    }
                    i++;
                }
            }
        }
        return st.size()*2+c;
    }
};