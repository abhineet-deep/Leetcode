class Solution {
public:
    void nextPermutation(vector<int>& nums) {


        int ind=-1,n=nums.size();
        for(int i=n-2;i>=0;i--) {
            if(nums[i] < nums[i+1]) {
                ind = i;
                break;
            }
        }
        cout<<ind<<" ";
        if(ind !=-1) {
            for(int i= n-1;i>=0;i--) {
                if(nums[i] > nums[ind]) {
                    int temp = nums[i];
                    nums[i] = nums[ind];
                    nums[ind] = temp;
                    break;
                }
            }
        }
        sort(nums.begin()+ind+1,nums.end());
    }
};