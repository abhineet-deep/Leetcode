class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int count = 0,maxi = 0;
        int i=0,j=0;
        while(j<s.size()) {
            mpp[s[j]]++;
            
            if(mpp[s[j]] > 1) {
                while(mpp[s[j]] > 1) {
                    mpp[s[i]] --;
                    i++;
                }
            }
            maxi =max(maxi, j-i+1);
            j++;
        }
        
        
        return maxi;
    }
};