class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        
        int i = startPos[0], j = startPos[1], x = homePos[0], y = homePos[1];
        /*
            Рекурсия с кэшем не пройдет по времени, потому что входные данные слишком больше
            Да и нет смысла просчитывать смещение по вертикали с каждой клетки на горизонтали,
            потом что стоимость такого смещения будет всегда одинаковая по массиву colCosts.
            
            Поэтом идея такая:
            Сначала ищем минимальный путь по горизонтали, затем минимальный путь по вертикали,
            и в качестве ответа нужно проссумировать их стоимости.
        */
        
        int sum = 0;
        while (i != x) { 
            i += (x - i) / abs(x - i);
            sum += rowCosts[i];
        }
        
        while (j != y) {
            j += (y - j) / abs(y - j);
            sum += colCosts[j];
        }
        
        return sum;
        
    }
};