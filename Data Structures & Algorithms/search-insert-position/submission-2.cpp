class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target<nums[0])return 0;
        int start=0;
        int end=nums.size();
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target && nums[mid+1]>target){
                return mid+1;
            }else  if(nums[mid]<target){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return end;
    }
};