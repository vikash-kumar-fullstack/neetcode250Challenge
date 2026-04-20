class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() < k) return -1; 
        priority_queue<int,vector<int>,greater<int>>que;
        for(int i=0;i<k;i++){
            que.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            if(que.top()<nums[i]){
                que.pop();
                que.push(nums[i]);
            }
        }
        return que.top();
    }
};
