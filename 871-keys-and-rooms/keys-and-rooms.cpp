class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visit(n,false);
        dfs(0,rooms,visit);
        for(int i=0;i<n;i++){
            if(!visit[i]){
                return false;
            }
        }
        return true;
    }
    void dfs(int idx,vector<vector<int>>& rooms,vector<bool>&visit){
        visit[idx]=true;
        for(int num:rooms[idx]){
            if(!visit[num]){
                dfs(num,rooms,visit);
            }
        }
    }
};