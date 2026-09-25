class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int left=0,right=0;
        int f=-1;
        int max_len=-1;
        while(right < arr.size()-1){
            if(arr[right] > arr[right+1]){
                if(f==-1){
                    f=1;
                    right++;
                }
                else if(f==0){
                    f=1;
                    right++;
                }else{
                    max_len=max(max_len,right-left+1);
                    left=right;
                    f=-1;
                }
            }
            else if(arr[right] < arr[right+1]){
                if(f==-1){
                    f=0;
                    right++;
                }
                else if(f==1){
                    f=0;
                    right++;
                }else{
                    max_len=max(max_len,right-left+1);
                    left=right;
                    f=-1;
                }
            }else{
                max_len=max(max_len,right-left+1);
                right++;
                left=right;
                f=-1;
            }
        }
        max_len=max(max_len,right-left+1);
        return max_len;
    }
};