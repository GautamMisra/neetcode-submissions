class Solution {
public: //recursion->memorization
    int solve(vector<int>& nums, vector<int>& dp, int i){
        if(i>=nums.size())
            return 0;
        if(dp[i]!=-1)  //return the value of dp[i] if a value exists
            return dp[i];
        dp[i]=max(nums[i]+solve(nums,dp,i+2),solve(nums,dp,i+1));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1); 
        return solve(nums,dp,0);
    }
};
