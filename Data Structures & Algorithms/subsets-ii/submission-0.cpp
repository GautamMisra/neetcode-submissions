class Solution {
public:
    void subset(vector<int>&nums,vector<int>&cur,vector<vector<int>>&ans,int i){
        ans.push_back(cur);
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1])
                continue;
            cur.push_back(nums[j]);
            subset(nums,cur,ans,j+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>cur;
        subset(nums,cur,ans,0);
        return ans;
    }
};
