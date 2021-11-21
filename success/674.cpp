class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int result = 1;
        int cur = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                cur++;
            }
            else {
                result = max(result, cur);
                cur = 1;
            }
        }
        
        return max(result, cur);
    }
};