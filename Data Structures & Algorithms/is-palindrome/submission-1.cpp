class Solution {
public:
    bool isPalindrome(string s) {
        string x="";
        string y="";
        char c;
        for (char c : s) {
            if (c != ' '&& isalnum(c)) 
                x+=tolower(c);
        }
        for (int i = x.length() - 1; i >= 0; --i){
             y += x[i];
        }
        return x==y;
    }
};
