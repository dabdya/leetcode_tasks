class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        /*
            Сразу же приходит в голову решение за линию, когда
            нужно взять поэлементный xor, ответом будет xor всех элементов
        */
        
        // Модифицированный бинарный поиск по неявному запросу
        
        int lp = 0; 
        int rp = nums.size() - 1;
        
        while (lp != rp) {
            
            int m = (lp + rp) / 2;

            if (m - 1 >= 0 && nums[m - 1] != nums[m] && m + 1 == nums.size()) {
                return nums[m];
            }
            
            if (m - 1 >= 0 && nums[m - 1] != nums[m] && nums[m + 1] != nums[m]) {
                return nums[m];
            }
            
            if (m + 1 != nums.size() && nums[m + 1] != nums[m] && m - 1 < 0) {
                return nums[m];
            }
            
            if (m + 1 != nums.size() && nums[m + 1] != nums[m] && nums[m - 1] != nums[m]) {
                return nums[m];
            }
            
            int k = (nums[m] == nums[m - 1]) ? m - 1 : m;
            if (k != 0 && k % 2 != 0) {
                rp = m;
            }
            else {
                lp = m + 1;
            }         
        }
        
        return nums[lp];
    }
};