class Solution {
public:
    vector<vector<int>>ans;
    void fun(int ele,int n,int k,vector<int>&nums,vector<bool>&visit){
        if(k==0){
            ans.push_back(nums);
            return;
        }
        for(int i=ele;i<=n;i++){
            if(!visit[i]){
                nums.push_back(i);
                visit[i]=true;
                fun(i+1,n,k-1,nums,visit);
                nums.pop_back();
                visit[i]=false;
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
         vector<int>nums;
         vector<bool>visit(n+1,false);
         fun(1,n,k,nums,visit);
         return ans;
    }
};