class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i,j,profit=0,ans=0;
        for(i=0;i<n;i++){
            for(j=n-1;j>i;j--){
                profit=prices[j]-prices[i];
                ans=max(ans,profit);
            }
        }
        return ans;      
    }
};
