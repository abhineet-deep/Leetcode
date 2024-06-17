class Solution {
public:
    void twoSum(vector<int>& nums,int target, vector<vector<int>>& res,int x) {
        
        for(int i = x+1;i<nums.size();i++) {
            if(i>x+1 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = nums.size()-1;
            while(j<k) {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[x];
                if(sum>target) k--;
                else if(sum<target) j++;
                else {
                    vector<int> vec = {nums[x],nums[i],nums[j],nums[k]};
                    res.push_back(vec);
                    j++;
                    k--;
                    while(j<k && nums[k] == nums[k+1]) k--;
                    while(j<k && nums[j] == nums[j-1]) j++;
                }
            } 
        }
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int x = 0;x<nums.size();x++) {
            if(x>0 && nums[x] == nums[x-1]) continue;
            twoSum(nums,target,res,x);
        }
        
        return res;
    }
};