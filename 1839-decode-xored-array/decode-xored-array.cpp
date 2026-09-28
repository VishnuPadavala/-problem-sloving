class Solution {
public:
    vector<int> decode(vector<int>& e, int first) {
        vector<int>ans;
        ans.push_back(first);
        for(int i=0;i<e.size();i++){
            ans.push_back(ans.back()^e[i]);
        }
        return ans;
    }
};