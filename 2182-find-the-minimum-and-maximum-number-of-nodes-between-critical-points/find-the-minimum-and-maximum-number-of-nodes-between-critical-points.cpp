/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *next,*curr,*prev;
        curr=head;
        int count=1;
        vector<int>v;
        next=curr->next;
        while(next->next){
            count++;
            prev=curr;
            curr=curr->next;
            next=next->next;
            if(prev->val > curr->val && next->val > curr->val){
                v.push_back(count);
            }
            else if(prev->val<curr->val && next->val<curr->val){
                v.push_back(count);
            }
            else {
                continue;
            }
        }
        sort(v.begin(),v.end());
        if(v.empty())return {-1,-1};
        if(v.size()==1)return {-1,-1};
        int small=INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            small=min(small,v[i+1]-v[i]);
        }
        return {small,v[v.size()-1]-v[0]};
    }
};