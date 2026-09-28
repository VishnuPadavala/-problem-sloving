class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        stack<int>st;
        for(int i=0;i<as.size();i++){
            if(!st.empty()){
                if(as[i]<0){
                    int f=1;
                    while(!st.empty() && st.top()>=0){
                        if(abs(as[i])>abs(st.top())){
                            st.pop();
                        }else if(abs(as[i])==abs(st.top())){
                            st.pop();
                            f=0;
                            break;
                        }else{
                            f=0;
                            break;
                        }
                    }
                    if(f){
                        st.push(as[i]);
                    }
                }else{
                    st.push(as[i]);
                }
            }else{
                st.push(as[i]);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};