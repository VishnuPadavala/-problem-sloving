class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double,pair<int,int>>>pq;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                pq.push_back({(double)arr[i]/arr[j],{arr[i],arr[j]}});
            }
        }
        sort(pq.begin(),pq.end());
        return {pq[k-1].second.first,pq[k-1].second.second};
    }
};