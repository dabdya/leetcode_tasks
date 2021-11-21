class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        return search(nums, k, 0, 0);
    }
    
private:
    map<pair<int, int>, double> cache;
    
    double search(const vector<int>& nums, int k, int j, int h) {
        
        if (cache.count({ j, h }) == 1) return cache[{ j, h }];
        
        if (j == nums.size() - 1) {
            return nums[j];
        }
        
        double best = .0;
        double avg = .0;
        int n = 0;
        
        for (int i = j; i < nums.size(); i++) {
            
            avg += static_cast<double>(nums[i]);
            n++;
            
            double res = (h + 1 != k) ? 
                search(nums, k, i + 1, h + 1) : 0;
            
            if (h + 1 == k) {
                best = avg / n;
            }
            else if (avg / n + res > best) {
                best = avg / n + res;
            }
            
        }
        
        cache[{ j, h }] = best;
        return best;
        
    }
};