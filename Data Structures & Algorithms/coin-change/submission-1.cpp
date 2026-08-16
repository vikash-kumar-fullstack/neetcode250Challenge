class Solution {
public:
    int coin(vector<int>&coins, int amount){
        if(amount<=0)return 0;
        int ans=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(amount-coins[i]>=0){
            int res=coin(coins,amount-coins[i]);
            if(res!=INT_MAX)
                ans=min(ans,res+1);
            }
        }
        return ans;
    }
    int soldp(vector<int>&coins,int amount,vector<int>&dp){
        if(amount<=0)return 0;
        if(dp[amount]!=-1)return dp[amount];
        int ans=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(amount-coins[i]>=0){
            int res=soldp(coins,amount-coins[i],dp);
            if(res!=INT_MAX)
                ans=min(ans,res+1);
            }
        }
        dp[amount]=ans;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // int solv=coin(coins,amount);
        // return solv==INT_MAX?-1:solv;
        vector<int>dp(amount+1,-1);
        int solv=soldp(coins,amount,dp);
        return solv==INT_MAX?-1:solv;
    }
};
