class Solution {
public:
    int findMin(vector<int>& nums) {
        
        /*  Задача в том, чтобы найти точку перегиба - это и будет минимальный элемент
            в массиве. Изначально в отсортированном массиве [0,1,2,4,5,6,7] последний
            элемент больше чем первый элемент. Когда мы делаем сдвиг, то получается так,
            что последний элемент будет всегда меньше чем первый. Например:
            
                > [4,5,6,7,0,1,2] -> точка перегиба 0 в правой части
                > [7,0,1,2,4,5,6] -> точка перегиба 0 в левой части
            
            Заранее проверим базовый случай когда ротаций не было, иначе наименьший элемент
            всегда находится где-то в середине.
            
            Воспользуемся обычным бинарным поиском. Сдвиг точно был. Условие перехода:
            Если мид больше чем первый элемент, то идем вправо, поскольку слева все элементы меньше
            Если мид меньше чем первый элемент, то идем влево, посскольку справа все элементы больше
            
        */
        
        if (nums[0] < nums[nums.size() - 1]) {
            return nums[0];
        }
        
        return BinarySearch(nums, 0, nums.size() - 1);
    }

private:
    int BinarySearch(const vector<int>& nums, int lp, int rp) {
        
        while (lp != rp) {
            int m = (lp + rp) / 2;
            if (nums[m] >= nums[0]) {
                lp = m + 1;
            }
            else {
                rp = m;
            }
        }
        
        return nums[lp];
        
    }
};