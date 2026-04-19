class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>ans;
        for(auto it:nums){
            ans[it]++;
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]>nums.size()/2){
                return i;
            }
        }
        return 0;
    }
};