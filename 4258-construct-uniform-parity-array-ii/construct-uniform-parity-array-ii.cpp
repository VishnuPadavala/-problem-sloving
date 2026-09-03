class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int>even,odd;
        for(int num:nums1){
            if(num%2==0){
                even.push_back(num);
            }
            else{
                odd.push_back(num);
            }
        }
        if(odd.size()==0 || even.size()==0){
            return true;
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        int a=even[even.size()-1];
        int f1=0;
        for(int i=0;i<odd.size();i++){
            if(a>odd[i]){
                f1=1;
                break;
            }
        }
        int b=even[0];
        int f2=0;
        for(int i=0;i<odd.size();i++){
            if(b>odd[i]){
                f2=1;
                break;
            }
        }
        if(f1==1 && f2==1){
            return true;
        }
        return false;
        // int f2=0;
        // for(int i=0;i<odd.size();i++){
        //     int f=1;
        //     for(int j=0;j<even.size();j++){
        //         if(odd[i]-even[j]>=1){
        //             f=0;
        //             break;
        //         }
        //     }
        //     if(f==1){
        //         f2=1;
        //         break;
        //     }
        // }
        // if(f2==0){
        //     return true;
        // }
        return false;
    }
};