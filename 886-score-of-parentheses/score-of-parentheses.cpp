class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(0);
            }else{
                if(st.top()==0){
                    st.pop();
                    if(!st.empty() && st.top()!=0){
                        int ele=1;
                        while(!st.empty() && st.top()!=0){
                            int ele2=st.top();
                            ele+=ele2;
                            st.pop();
                        }
                        st.push(ele);
                    }else{
                        st.push(1);
                    } 
                }else{
                    int ele=st.top();
                    st.pop();
                    ele*=2;
                    while(!st.empty() && st.top()!=0){
                        int ele2=st.top();
                        ele+=ele2;
                        st.pop();
                    }
                    st.pop();
                    while(!st.empty() && st.top()!=0){
                        int ele2=st.top();
                        ele+=ele2;
                        st.pop();
                    }
                    st.push(ele);
                }
            }
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};