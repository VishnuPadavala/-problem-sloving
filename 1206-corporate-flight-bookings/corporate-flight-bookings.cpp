class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>prefix(n+1,0);
        for(auto &e:bookings){
            for(int i=e[0];i<=e[1];i++){
                prefix[i]+=e[2];
            }
        }
        vector<int>ans;
        for(int i=1;i<n+1;i++){
            ans.push_back(prefix[i]);
        }
        return ans;
    }
};