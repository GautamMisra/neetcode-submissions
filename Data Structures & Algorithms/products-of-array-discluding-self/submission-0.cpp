class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int product=1;
            for(int j=0;j<n;j++){
                if(i!=j){
                    product=(nums[j]*product);
                }
            }
            output.push_back(product);
        }
        vector<int> res;
        int k=output.size();
        for(int i=0;i<k;i++){
            res.push_back(output[i]);
        }
        return res;
    }
};
