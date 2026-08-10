class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i=0,j=0,c=1;
        vector<vector<int>>nums(n,vector<int>(n));
        while(n>0){
            if(n==1)break;
            for(int k=0;k<n-1;k++){
                nums[i][j]=c++;
                j++;
            }
            for(int k=0;k<n-1;k++){
                nums[i][j]=c++;
                i++;
            }
            for(int k=0;k<n-1;k++){
                nums[i][j]=c++;
                j--;
            }
            for(int k=0;k<n-1;k++){
                nums[i][j]=c++;
                i--;
            }
            n-=2;
            i++;
            j++;
        }
        if(n==1)nums[i][j]=c;
        return nums;
    }
};