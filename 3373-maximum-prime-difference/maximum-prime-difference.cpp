class primetable{
    private:
    int max_val=101;
    vector<bool>prime=vector<bool>(101, true);
    public:
    primetable(){
        prime[0]=prime[1]=false;
        for(int i=2;i*i<=max_val;i++){
            if(!prime[i]){
                continue;
            }
            for(int j=i*i;j<=max_val;j+=i){
                prime[j]=false;
            }
        }
    }
    bool check(int n){
        return prime[n];
    }
};

primetable p;
class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(p.check(nums[i])){
                ans.push_back(i);
            }
        }
        return abs(ans.back()-ans[0]);
    }
};