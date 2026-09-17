class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        string s="";
        vector<vector<string>>ans;
        for(int i=0;i<searchWord.size();i++){
            vector<string>nums;
            s+=searchWord[i];
            int k=0;
            for(int j=0;j<products.size();j++){
                if((i+1) <= products[j].size()){
                    string sub=products[j].substr(0,i+1);
                    if(sub==s){
                        nums.push_back(products[j]);
                    }
                }
            }
            vector<string >dupli;
            sort(nums.begin(),nums.end());
            for(int j=0;j<nums.size() && k<3 ;j++,k++){
                dupli.push_back(nums[j]);
            }
            ans.push_back(dupli);
        }
        return ans;
    }
};