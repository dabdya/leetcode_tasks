class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        /*
            До этого делал сортировку на каждую подходящую комбинацию,
            оказывается достаточно сделать это лишь один раз в самом начале для исходного массива
        */
        sort(begin(candidates), end(candidates));
        search(0, candidates, target);
        return combinations;
    }
    
private:
    vector<vector<int>> combinations;
    vector<int> combination;
    
    void search(int sum_, const vector<int>& nums, const int& target) {
        
        int n = nums.size();
        
        if (sum_ > target) {
            return;
        }
        
        if (sum_ == target) {
            // vector<int> copy_(combination.size());
            // partial_sort_copy(
            //     begin(combination), end(combination), begin(copy_), end(copy_));
            combinations.push_back(combination);      
        }
        else {
            
            for (int k = 0; k < n; k++) {
                /* 
                    Поскольку кандидаты отсортированы изначально, то не надо учитывать
                    комбинации в которых следующий кандидат меньше чем предыдущий, потому
                    что ранее если ответ для таких чисел существует, то он был найден ранее
                    в обратном порядке. И сейчас найдется, только это будет дубликат.
                */
                if (combination.size() > 0 && nums[k] < combination[combination.size() - 1]) {
                    continue;
                }
                combination.push_back(nums[k]);
                search(sum_ + nums[k], nums, target);
                combination.pop_back();
            }
            
        }
    }
};