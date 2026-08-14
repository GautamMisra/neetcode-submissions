class Solution {
public:
    int characterReplacement(string s, int k) {
        int hash[26]={0},i=0,j=0,maxf=0,maxlength=0,valid;
        while(j<s.length()){
            hash[s[j]-'A']++;
            maxf=max(maxf,hash[s[j]-'A']);
            valid=(j-i+1)-maxf;
            if(valid<=k){
                maxlength=max(j-i+1,maxlength);
            }
            else{
                while(((j-i+1)-maxf)>k){
                    hash[s[i]-'A']--;
                    i++;
                }
            }
            j++;
        }
        return maxlength;
    }
};
