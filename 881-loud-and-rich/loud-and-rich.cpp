class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>>edge(n);
        for(auto &e:richer){
            edge[e[1]].push_back(e[0]);
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            queue<int>q;
            vector<bool>visit(n);
            q.push(i);
            visit[i]=true;
            int idx=i;
            while(!q.empty()){
                int person=q.front();
                q.pop();
                if(quiet[person]<quiet[idx]){
                    idx=person;
                }
                for(int richchlid:edge[person]){
                    if(!visit[richchlid]){
                    q.push(richchlid);
                    visit[richchlid]=true;
                    }
                }
            }
            ans[i]=idx;
        }
        return ans;
    }
};