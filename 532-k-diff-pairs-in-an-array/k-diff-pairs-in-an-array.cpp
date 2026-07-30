class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        set<pair<int,int>>s;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i]-k)){
                s.insert({nums[i],nums[i]-k});
            }
            m[nums[i]]++;
        }
        return s.size();
    }
};