class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        /*
            Для начала нужно отсортировать все числа по возрастанию. Таким образом 
            для каждоо числа все его потенциальные делители будут по одну сторону.
            
            Далее заведем масcив dp размера nums и проинициализируем его единицами
            Запускаем цикл for по каждому элементу, dp[i] = dp[j] + 1, где j индекс
            делителя числа nums[i] с наибольшим значением в массиве dp.
            
            То есть просматриваем все делители и выбираем такой, который имеет больше всего
            делителей для себя. Например,
            
            nums 1 4 7 8 16
            dp   1 2 2 3 4
            
            https://leetcode.com/problems/largest-divisible-subset/discuss/684677/3-STEPS-c%2B%2B-or-python-or-java-dp-PEN-PAPER-DIAGRAM
        */
        
        size_t n = nums.size();
        
        vector<pair<int, int>> dp;
        dp.assign(n, {1, -1});
        
        sort(begin(nums), end(nums));
        
        for (int i = 1; i < n; i++) {
            int j = FindLargestDivisorIndex(nums, dp, i);
            if (j != -1) {
                dp[i] = { dp[j].first + 1, j };
            }    
        }
        
        int max_index = n - 1;
        pair<int, int> max_e = dp[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (dp[i].first > max_e.first) {
                max_e = dp[i];
                max_index = i;
            }
        }
        
        vector<int> result = { nums[max_index] };
        
        int i = dp[max_index].second;
        while (i != -1) {
            result.push_back(nums[i]);
            i = dp[i].second;
        }
        
        return result;
    }
    
private:
    int FindLargestDivisorIndex(
        const vector<int>& nums, const vector<pair<int, int>>& dp, int start) {
        
        int result = -1;
        for (int i = start - 1; i >= 0; i--) {
            if (nums[start] % nums[i] == 0) {
                if (result == -1 || dp[i].first > dp[result].first) {
                    result = i;
                }
            }
        }
        
        return result;
    }
};