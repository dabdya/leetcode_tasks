class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // Simple O(n) time and O(n) space
//         map<int, int> freq;
        
//         for (const auto& num : nums) {
//             freq[num]++;
//         }
        
//         for (const auto& [k, v] : freq) {
//             if (v > nums.size() / 2) return k;
//         }
        
//         return -1;
        
        int count = 0;
        int candidate = 0;
        for (const auto& num : nums) {
            if (count == 0) candidate = num;
            count += (candidate == num) ? 1 : -1;
        }
        
        return candidate;
    }
};