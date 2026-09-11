class Solution {
public:
    string sortSentence(string s) {
        vector<pair<int,string>>nums;
        string s1="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                continue;
            }
            if(isdigit(s[i])){
                int idx=(s[i]-'0');
                nums.push_back({idx,s1});
                s1="";
            }else{
                s1+=s[i];
            }
        }
        sort(nums.begin(),nums.end());
        string ans="";
        for(int i=0;i<nums.size();i++){
            if((nums.size()-1)==i){
                ans+=nums[i].second;
            }else{
                ans+=nums[i].second;
                ans+=" ";
            }
        }
        return ans;
    }
};