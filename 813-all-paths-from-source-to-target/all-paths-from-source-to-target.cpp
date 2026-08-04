class Solution {
public:
    vector<vector<int>>ans;
    int target=0;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>nums;
        nums.push_back(0);
        target=graph.size()-1;
        travel(graph,0,nums);
        return ans;
    }
    void travel(vector<vector<int>>& graph,int idx,vector<int>&nums){
        if(idx==target){
        ans.push_back(nums);
        return;
        }
        for(int num:graph[idx]){
            nums.push_back(num);
            travel(graph,num,nums);
            nums.pop_back();
        }
    }
};