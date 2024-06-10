class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> checker = heights;
        int count = 0;
        sort(begin(checker), end(checker));
        for (int i = 0; i < heights.size(); i++) count += heights[i] != checker[i];
        return count;
    }
};