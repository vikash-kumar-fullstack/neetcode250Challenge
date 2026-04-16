class Solution {
public:

    void solve(vector<int>&nums,vector<vector<int>>&ans,int i){
        if(i>=nums.size()){
            if(std::find(ans.begin(),ans.end(),nums)==ans.end())
            ans.push_back(nums);
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[j],nums[i]);
            solve(nums,ans,i+1);
            swap(nums[j],nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(nums,ans,0);
        return ans;
    }

};