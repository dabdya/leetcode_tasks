class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if (k == 0 || k == 1) return 0;
        
        int n = nums.size();
        int result = 0;
        int product = 1;
        
        int j = 0;
        for (int i = 0; i < n; i++) {
            
            product *= nums[i];
            while (product >= k) {
                result += i - j;
                product /= nums[j];
                j++;
            }
            
        }

        for (int i = n - j; i > 0; i--) {
            result += i;
        }
        
        return result;
        // time: O(2n), space: O(1)
    }
};