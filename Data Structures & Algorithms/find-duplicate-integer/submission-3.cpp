class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size(),ans;
        unordered_map<int, int> hash;
        for(int i=0;i<n;i++){
            hash[nums[i]]+=1;
        }
        for(int i=1;i<=n;i++){
            if(hash[i] > 1)
                ans=i;
        }
        return ans;
    }
};
