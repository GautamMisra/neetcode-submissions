class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size(),sum=0;
        for(int i=0;i<n;){
            for(int j=n-1;j>=0;){
                sum=numbers[i]+numbers[j];
                if(sum<target){
                    sum=0;
                    i++;
                }
                else if(sum>target){
                    sum=0;
                    j--;
                }
                else
                    return{i+1,j+1};
            }
        }
    }
};
