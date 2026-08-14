class Solution {
public:
    void subsets(vector<int> &arr,vector<int> &cur,vector<vector<int>> &res,int i){
        if(i==arr.size()){
            res.push_back(cur);
            return;
        }
        cur.push_back(arr[i]);
        subsets(arr,cur,res,i+1);
        cur.pop_back();
        subsets(arr,cur,res,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        subsets(nums,cur,res,0);
        return res;
    }
};
