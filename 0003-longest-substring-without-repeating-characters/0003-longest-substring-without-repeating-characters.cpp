class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,-1);
        int l = 0, r = 0;
        int n = s.size();
        int len = 0;
        int maxi = 0;

        while(r < n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }
            }
            len = r - l + 1;
            maxi = max(len,maxi);
            hash[s[r]] = r;
            r++;
        }
        return maxi;
    }
};