class Solution {
public:
    int jump(vector<int>& nums) {
        
        int start = 0;
        int end = 0;
        int jumps = 0;
        
        /*
            Поддерживается range(lp, rp), в котором проверяется каждое число на прыжок
            сразу до конечного элемента, при этом нужно хранить число прыжков до этого range.
            Если i in range(lp, rp) и с i можно допрыгнуть до конца, то ответ jumps + 1;
            Если нельзя допрыгнуть ни с одного числа из range, то range обновляется, при чем
            конец становится максимально достижимым элементом, а начало сдиваегтся на конец.
            
            [2,3,1,1,4] , lp = 0, rp = 0, jumps = 1
            В range(0,0) есть только элемент 2, с него нельзя допрыгнуть до конца.
            Значит надо будет сделать прыжок на другой range, т.е. делаем jumps++. А новый
            range будет такой: range(1,2), т.к. начало сдвинулось на предыдущий конец + 1,
            а конец стал максимально достижимым из элементов отрезка range(0,0).
        */
        
        while (end < nums.size() - 1) {
            jumps++;
            int maxend = 0;
            for (int i = start; i <= end; i++) {
                if (nums[i] >= nums.size() - i - 1) {
                    return jumps;
                }
                maxend = max(maxend, i + nums[i]);
            }
            start = end + 1;
            end = maxend;
        }
        
        return jumps;
    }
};