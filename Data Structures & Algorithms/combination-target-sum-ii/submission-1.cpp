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
        for (int j = i; j < arr.size(); j++) {
            if (j > i && arr[j] == arr[j - 1])
                continue;
        cur.push_back(arr[j]);
        subset(arr,cur,res,target,j+1,sum+arr[j]);  //keeping going till last i
        cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        vector<vector<int>> res;
        int sum=0;
        subset(candidates,cur,res,target,0,sum);
        return res;
    }
};
