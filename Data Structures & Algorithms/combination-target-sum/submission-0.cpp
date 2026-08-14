class Solution {
public:
    void subset(vector<int> &arr,vector<int> &cur,vector<vector<int>> &res,int target,int i,int sum){
        if (sum == target) {
            res.push_back(cur);
            return;
        }
        if (sum > target || i == arr.size()) {
            return;
        }
        cur.push_back(arr[i]);
        subset(arr,cur,res,target,i,sum+arr[i]);
        cur.pop_back();
        subset(arr,cur,res,target,i+1,sum);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        vector<vector<int>> res;
        int sum=0;
        subset(nums,cur,res,target,0,sum);
        return res;
    }
};
