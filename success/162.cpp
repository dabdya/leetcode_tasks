#include <bits/stdc++.h>

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        pair<int, int> peak = BinarySearch(nums, 0, nums.size() - 1); 
        return peak.second;
    }
    
private:
    void TryUpdatePeak(pair<int, int>& peak, const pair<int, int>& applicant) {
        
        if (peak.first < applicant.first) {
            peak.first = applicant.first;
            peak.second = applicant.second;
        }

    }
    
    pair<int, int> BinarySearch(const vector<int>& nums, int lp, int rp) {
        
        pair<int, int> peak = {INT_MIN, 0};
        
        int m = (lp + rp) / 2;
        TryUpdatePeak(peak, {nums[m], m});
        
        if (lp != rp) {          
            TryUpdatePeak(peak, BinarySearch(nums, m + 1, rp));
            TryUpdatePeak(peak, BinarySearch(nums, lp, m));
        }
        
        return peak;
    }
};