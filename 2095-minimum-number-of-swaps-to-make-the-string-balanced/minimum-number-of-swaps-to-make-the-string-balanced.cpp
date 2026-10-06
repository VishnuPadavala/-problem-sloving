class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(char ch:s){
            if(ch=='['){
                st.push(ch);
            }else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        int size=st.size();
        if(size%2!=0){
            return (size+1)/2;
        }
        return size/2;
    }
};