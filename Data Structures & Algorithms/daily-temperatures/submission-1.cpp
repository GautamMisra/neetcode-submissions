class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(temperatures[j]>temperatures[i]){
                    ans[i]=j-i;
                    break;
                }
                else if(temperatures[j]<temperatures[i] && i!=n-1){
                    continue;
                }
                else{
                    ans[i]=0;
                }
            }
        }
        return ans;
    }
};
