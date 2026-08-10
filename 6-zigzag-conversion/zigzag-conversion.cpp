class Solution {
public:
    string convert(string s, int numRows) {
        string s1="";
        if(numRows==1)return s; 
        int n=2*(numRows-1),idx=0;
        int left=n,right=0;
        while(idx<numRows){
            int f=0;
            if(left!=0 && right!=0){
                for(int i=idx;i<s.size();){
                    s1+=s[i];
                    if(f==0){
                        i+=left;
                        f=1;
                    }else{
                        i+=right;
                        f=0;
                    }
                }
            }else{
                for(int i=idx;i<s.size();i=i+left+right){
                    s1+=s[i];
                }
            }
            left-=2;
            right+=2;
            idx++;
        }
        return s1;
    }
};