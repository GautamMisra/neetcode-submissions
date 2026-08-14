class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int i, j, temp;
        int n=nums.size();
        unordered_map<int, int> hash;
        for(i=0;i<n;i++){
            hash[nums[i]]+=1;
        }
        
        vector<int> index;
        for(auto x:hash){
            int key=x.first;
            int value=x.second;
            index.push_back(key);
        }

        for(i=0;i<index.size();i++){
            for(j=i+1;j<index.size();j++){
                if (hash[index[i]] < hash[index[j]]){
                    temp=index[j];
                    index[j]=index[i];
                    index[i]=temp;
                }
            }
        }

        vector<int> res;
        for(i=0;i<k;i++){
            res.push_back(index[i]);
        }
        return res;
    }
};
