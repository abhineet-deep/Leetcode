class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Dutch National Flag Algorithm

        int red = 0,blue=nums.size()-1,white=0;
        while(red<=blue) {
            if(nums[red] == 0) {
                swap(nums[white],nums[red]);
                white++;
                red++;
            }
            else if(nums[red] == 1) {
                red++;
            }
            else if(nums[red] == 2) {
                swap(nums[red],nums[blue]);
                blue--;
            }
        }
        return;
    }
};