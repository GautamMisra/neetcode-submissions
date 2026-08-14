class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.length() > s2.length())
            return false;

        int target[26] = {0};
        int window[26] = {0};

        for(char c : s1)
            target[c - 'a']++;

        int l = 0, r = 0;

        while(r < s2.length())
        {
            window[s2[r] - 'a']++;

            if((r - l + 1) > s1.length())
            {
                window[s2[l] - 'a']--;
                l++;
            }

            if((r - l + 1) == s1.length())
            {
                bool same = true;

                for(int i = 0; i < 26; i++)
                {
                    if(window[i] != target[i])
                    {
                        same = false;
                        break;
                    }
                }

                if(same)
                    return true;
            }

            r++;
        }

        return false;
    }
};
