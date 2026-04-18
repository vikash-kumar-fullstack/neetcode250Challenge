class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp(3);
        sort(nums.begin(),nums.end());
        int f=0;
        for(int i=0;i<nums.size()-2;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            f=i;
            temp[0]=nums[i];
            int st=i+1;
            
            int end=nums.size()-1;
            
            while(st<end){
                temp[1]=nums[st];
                temp[2]=nums[end];
                if(nums[i]+nums[st]+nums[end]==0 && st!=end){
                    ans.push_back(temp);
                    st++;
                    end--;

                    while(st < end && nums[st] == nums[st-1]) st++;
                    while(st < end && nums[end] == nums[end+1]) end--;

                }else if(nums[i]+nums[st]+nums[end]>0){
                    end--;
                }else{
                    st++;
                }
            }
        }return ans;
    }
};
