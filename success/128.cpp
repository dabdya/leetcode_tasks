class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.size() == 0 || nums.size() == 1) {
            return nums.size();
        }
        
        nums = digit_sort(nums);
        
        int longest = 1, current = 1;
        int last_num = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - last_num == 1) {
                current++;
            }
            else if (nums[i] - last_num == 0) {
                continue;
            }
            else {
                longest = max(longest, current);
                current = 1;
            }
            last_num = nums[i];
        }
        
        return max(longest, current);
    }
    
private:
    vector<int> digit_sort(const vector<int>& nums) {
        auto result = nums;
        sort(result.begin(), result.end());
        return result;
    }
};