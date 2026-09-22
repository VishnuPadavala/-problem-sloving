class Solution {
public:
    set<vector<int>>s;
    void fun(const vector<int>& nums,int n,vector<int>& a,vector<bool>&visit){
        if(a.size()==n){
            s.insert(a);
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<int>a;
        vector<bool>visit(n,false);
        fun(nums,n,a,visit);
        vector<vector<int>>ans;
        for(auto &num:s){
            ans.push_back(num);
        }
        return ans;
    }
};