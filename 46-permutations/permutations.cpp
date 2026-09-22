class Solution {
public:
    vector<vector<int>>ans;
    void fun(const vector<int>& nums,int n,vector<int>& a,vector<bool>&visit){
        if(a.size()==n){
            ans.push_back(a);
            return;
        }
        for(int i=0;i<n;i++){
            if(!visit[i]){
                a.push_back(nums[i]);
                visit[i]=true;
                fun(nums,n,a,visit);
                a.pop_back();
                visit[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>a;
        vector<bool>visit(n,false);
        fun(nums,n,a,visit);
        return ans;
    }
};