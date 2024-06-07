class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        
        unordered_map<int,int> mpp;

        for(int i=0;i<nums.size();i++) {
            mpp[nums[i]]++;
        }
        int res = 0;
        for(auto it : mpp) {
            if(it.second == 2) res^=it.first;
        }
        return res;
    }
};