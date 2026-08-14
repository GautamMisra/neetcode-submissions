class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       int n=nums.size();
       vector<vector<int>> ans;
       int i,j,k,sum=0;
       sort(nums.begin(), nums.end());
       for(i=0;i<n-2;i++){
            for(j=i+1;j<n-1;j++){
                for(k=j+1;k<n;k++){
                    sum=nums[i]+nums[j]+nums[k];
                    if(i > 0 && nums[i] == nums[i-1]) continue;
                    if(j > i+1 && nums[j] == nums[j-1]) continue;
                    if(k > j+1 && nums[k] == nums[k-1]) continue;
                    if(sum==0){
                         ans.push_back({nums[i],nums[j],nums[k]});
                    }
                    else{
                        sum=0;
                        continue;
                    }
                }
            }
       } 
       return ans;
    }
};
