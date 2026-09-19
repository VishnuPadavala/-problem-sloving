class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>>pq;
        for(int i=0;i<points.size();i++){
            int a=points[i][0],b=points[i][1];
            pq.push({(double)sqrt(pow(a,2)+pow(b,2)),{a,b}});
        }
        vector<vector<int>>ans;
        while(!pq.empty() && k!=0){
            auto &it=pq.top();
            int a=it.second.first,b=it.second.second;
            ans.push_back({a,b});
            pq.pop();
            k--;
        }
        return ans;
    }
};