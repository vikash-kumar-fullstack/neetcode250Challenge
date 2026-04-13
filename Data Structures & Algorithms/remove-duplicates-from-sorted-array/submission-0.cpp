class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=nums.size()-2;
        while(i>=0){
            if(nums[i+1]==nums[i]){
                nums.erase(nums.begin()+i+1);
            }
            i--;
        }
        return nums.size();
    }
};