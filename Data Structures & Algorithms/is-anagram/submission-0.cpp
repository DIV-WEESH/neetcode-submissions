class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m= t.length();
        if(n!=m)return false;

        unordered_map<char,int> freq;
        for(int i=0;i<n;i++)
        freq[s[i]]++;

        for(int i=0;i<n;i++)
        {
            freq[t[i]]--;
        }

        for(int i=0;i<n;i++)
        {
            if(freq[t[i]]!=0)return false;
        }
        return true;
    }
};
