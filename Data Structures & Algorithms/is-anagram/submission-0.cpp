#include<cstring>
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        bool value = (s == t);
        if(value)
            return true;
        else
            return false;
    }
};
