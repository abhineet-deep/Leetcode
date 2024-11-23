class Solution {
public:

    int maxRepeatingCharValue(int arr[]) {
        int maxi = INT_MIN;
        for(int i=0;i<26;i++) maxi = max(maxi,arr[i]);
        return maxi;
    } 

    int characterReplacement(string s, int k) {
        int l=0,r=0;
        int arr[26];
        int maxlen = INT_MIN;
        while(r<s.size()) {
            arr[s[r] - 65]++;
            int val = maxRepeatingCharValue(arr);
            int change = r-l+1 - val;

            while(change > k) {
                arr[s[l] - 65]--;
                l++;
                change = r-l+1 -  maxRepeatingCharValue(arr);
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }

        return maxlen;
    }
};