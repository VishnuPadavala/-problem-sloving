class Solution {
public:
    class TrieNode{
        public:
            TrieNode* child[2];
            TrieNode(){
                child[0]=child[1]=NULL;
            }
    };
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root=new TrieNode();
        int maxxor=0;
        for(int num:nums){
            TrieNode* node=root;
            TrieNode* xornode=root;
            int currxor=0;
            for(int i=31;i>=0;i--){
                int bit=(num >> i)&1;
                if(!node->child[bit]){
                    node->child[bit]=new TrieNode();
                }
                node=node->child[bit];
                int opposite=1-bit;
                if(xornode->child[opposite]){
                    currxor|=(1<<i);
                    xornode=xornode->child[opposite];
                }else{
                    xornode=xornode->child[bit];
                }
            }
            maxxor=max(maxxor,currxor);
        }
        return maxxor;
    }
};