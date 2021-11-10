class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 1) return nums[0];
        
        return max(not_circle_rob(nums, 0, n - 2), 
                   not_circle_rob(nums, 1, n - 1));
    }
    
private:
    int not_circle_rob(const vector<int>& nums, int lp, int rp) {
        
        int n = rp - lp + 1;
        vector<int> dp;
        dp.assign(n + 1, 0);
        
        dp[1] = nums[0 + lp];
        
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[lp + i-1]);
        }
        
        return dp[dp.size() - 1];
    }
};