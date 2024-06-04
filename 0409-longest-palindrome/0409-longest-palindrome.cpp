class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char,int> mpp;
        int oddCount = 0;
        for(int i = 0;i<s.size();i++) {
            mpp[s[i]]++;
            if(mpp[s[i]] % 2 != 0) oddCount++;
            else oddCount--;
        }
        if(oddCount > 1) return s.size() - oddCount + 1; 
        return s.size();

        // unordered_map<char,int> mpp;

        // for(int i = 0;i<s.size();i++) {
        //     mpp[s[i]]++;
        // }
        // int count = 0;
        // bool flag = true;
        // for(auto it : mpp) {
        //     if(it.second % 2 == 0) count+= it.second;
        //     else {
        //         if(flag) {
        //             count+=it.second;
        //             flag = false;
        //         }
        //         else count+=it.second-1;
        //     }
        // }
        // return count;
    }
};