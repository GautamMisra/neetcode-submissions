class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=int(s.length());
        int i=0,j=0,ans=0;
        string curr="";
        
        while(j<n){
            bool duplicate=false;
            for(int k=0;k<curr.length();k++){
                if(s[j]==curr[k]){
                    duplicate=true;
                    break;
                }
            }
            if(!duplicate){
                curr+=s[j];
                j++;
            }
            else{
                curr.erase(0,1);
                i++;
            }
            ans=max(ans,(int)curr.length());
        }
        return ans;
        
    }
};
