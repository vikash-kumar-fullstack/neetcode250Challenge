class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(auto it:nums){
            mp[it]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>que;
        for(auto &it:mp){
            que.push({it.second,it.first});
            if(que.size()>k){
                que.pop();
            }
        }
        while(!que.empty()){
            ans.push_back(que.top().second);
            que.pop();
        }
        return ans;
    }
};