class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        int result = n + 1;
        int sum_ = 0;
        
        int j = 0;
        for (int i = 0; i < n; i++) {
            sum_ += nums[i];
            while (sum_ >= target) {
                result = min(result, i - j + 1);
                sum_ -= nums[j];
                j++;
            }
        }
        return result == n + 1 ? 0 : result;
        
    }
};