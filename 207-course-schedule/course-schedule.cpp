class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        if(p.size()==0)return 1;
        vector<bool>visit(n);
        vector<int>indegree(n,0);
        vector<vector<int>>nums(n);
        for(auto &e : p){
            nums[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                visit[i]=1;
            }
        }
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                int curr=q.front();
                q.pop();
                for(int child:nums[curr]){
                    indegree[child]--;
                    if(indegree[child]==0){
                        q.push(child);
                        visit[child]=1;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!visit[i]){
                return false;
            }
        }
        return true;
    }
};