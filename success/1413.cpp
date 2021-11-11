class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        int sum = nums[0];
        int min_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            min_sum = min(min_sum, sum);
        }
        
        if (min_sum < 0) return abs(min_sum) + 1;
        return 1;
    }
};