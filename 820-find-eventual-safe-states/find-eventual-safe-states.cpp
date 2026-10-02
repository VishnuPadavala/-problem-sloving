class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>graph1(n);
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            indegree[i]=graph[i].size();
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                graph1[graph[i][j]].push_back(i);
            }
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                int ele=q.front();
                q.pop();
                for(int chlid:graph1[ele]){
                    indegree[chlid]--;
                    if(indegree[chlid]==0){
                        q.push(chlid);
                        ans.push_back(chlid);
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};