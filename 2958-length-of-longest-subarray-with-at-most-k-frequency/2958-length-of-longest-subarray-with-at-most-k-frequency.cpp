class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int left = 0, right = 0 ,maxi = 0;

        while(right < nums.size()) {
            mpp[nums[right]]++;
            if(mpp[nums[right]] > k) {
                while(mpp[nums[right]] > k) {
                    mpp[nums[left]]--;
                    left++;
                }
            }
            maxi = max(maxi,right-left+1);
            right++;
        }
        return maxi;
    }
};