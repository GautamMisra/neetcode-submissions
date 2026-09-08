class Solution {
public:
    int dfs(vector<int>& dp,int n){
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        if(n<=2)
            return n;
        dp[1]=1;
        dp[2]=2;
        dfs(dp,n);
        return dp[n];
    }
};
