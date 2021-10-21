class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 1) {
            return true;
        }
        
        int start;
        bool sign;
        // нужно определить характер монотонности
        for (int i = 1; i < n; i++) {
            int delta = nums[i] - nums[i-1];
            if (delta == 0) {
                continue;
            } 
            else {
                sign = delta > 0 ? true : false;
                start = i + 1;
                break;
            }
        }
        
        for (int i = start; i < n; i++) {
            int delta = nums[i] - nums[i-1];
            if (delta < 0 && sign || delta > 0 && !sign) {
                return false;
            }
        }
        
        return true;
        
    }
};