class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        // time O(n^2), space O(n)
        // return DynamicProgrammingApproach(nums);
        
        // time O(n*logn), space O(n)
        return BinarySearchApproach(nums);
    }
    
private:
    int DynamicProgrammingApproach(const vector<int>& nums) {
        vector<int> dp;
        dp.assign(nums.size(), 1);
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        
        return *max_element(begin(dp), end(dp));
    }
    
    int BinarySearchApproach(const vector<int>& nums) {
        
        vector<int> sub;
        for (int i = 0; i < nums.size(); i++) {
            if (sub.size() == 0 || nums[i] > sub[sub.size() - 1]) {
                sub.push_back(nums[i]);
            }
            else {
                int j = BinarySearch(sub, nums[i]);
                sub[j] = nums[i];
            }
        }
        
        return sub.size();
    }
    
    int BinarySearch(const vector<int>& sub, int item) {
        // Нужно найти индекс первого элемента который >= item
        int lp = 0;
        int rp = sub.size() - 1;
        
        while (lp != rp) {
            int m = (lp + rp) / 2;
            if (item > sub[m]) {
                lp = m + 1;
            }
            else {
                rp = m;
            }
        }
        
        return lp;
    }
};