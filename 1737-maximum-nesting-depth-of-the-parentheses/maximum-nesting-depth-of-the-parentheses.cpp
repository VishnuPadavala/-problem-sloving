class Solution {
public:
    int maxDepth(string s) {
        int count=0,max_p=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
                max_p=max(count,max_p);
            }
            else if(s[i]==')'){
                count--;
            }
            else{
                continue;
            }
        }
        return max_p;
    }
};