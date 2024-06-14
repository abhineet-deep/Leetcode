class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int increment = 0,need = 0;
        for(int i = 1;i<nums.size();i++) {
            need = max(nums[i-1],need) + 1;
            if(nums[i] < need) increment += need - nums[i];
            // cout<<increment<<" ";
        }
        return increment;
    }
};