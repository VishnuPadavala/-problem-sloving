class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int>ans;
        int i=0;
        while(i<s.size()){
            int r=startPos[0],c=startPos[1],count=0,f=0;
            for(int j=i;j<s.size();j++){
                if(s[j]=='R'){
                    c++;
                }else if(s[j]=='L'){
                    c--;
                }else if(s[j]=='U'){
                    r--;
                }else{
                    r++;
                }
                if(r<0 || c<0 || r>=n || c>=n){
                    break;
                }
                count++;
            }
            ans.push_back(count);
            i++;
        }
        return ans;
    }
};