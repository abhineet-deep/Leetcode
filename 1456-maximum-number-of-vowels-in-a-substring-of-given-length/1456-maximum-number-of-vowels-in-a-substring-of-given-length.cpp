class Solution {
public:
    bool vowels(char s) {
        if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') return true;
        return false;
    }

    int maxVowels(string s, int k) {
        int result = INT_MIN,subCount = 0;
        int left = 0,right = 0;
        while(right < s.size()) {
            if(right<k-1) {
                if(vowels(s[right])) subCount++;
                right++;
                continue;
            }
            if(vowels(s[right])) subCount++;
            result = max(result,subCount);
            if(vowels(s[left])) subCount--;

            right++;left++;
        }

        return result;
    }
};