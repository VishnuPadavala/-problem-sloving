class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>>edjes(n);
        vector<bool>visit(n,false);
        vector<int>indegree(n,0);
        for(auto &e:p){
            edjes[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
                visit[i]=1;
            }
        }
        vector<int>ans;
        while(!q.empty()){
               int s=q.size();
               for(int i=0;i<q.size();i++){
                    int ele=q.front();
                    ans.push_back(ele);
                    q.pop();
                    for(int child:edjes[ele]){
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
                return {};
            }
        }
        return ans;
    }
};