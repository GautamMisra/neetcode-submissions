class Solution {
public:
    int solve(vector<int>& nums,vector<int>& dp,int i,int end){
        if(i>end)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        if(i>=nums.size())
            return 0;
        dp[i]=max(nums[i]+solve(nums,dp,i+2,end),solve(nums,dp,i+1,end));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        vector<int>dp1(n,-1);
        int end=0,ans=0;
        ans=max(solve(nums,dp,0,n-2),solve(nums,dp1,1,n-1));
        if(n==1)
            ans=nums[0];
        return ans;
    }
};
