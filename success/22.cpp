class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        /*
            Всего 2n элементов, надо выбрать их так, чтобы была правильная скобочная последовательность
            Задачу можно сформулирвать так: выбрать все перестановки которые удовлетворяют правилам
            построения скобочных последовательностей. Однако лучше сделать перебор с возвратом, поскольку
            его сложность в худшем случае экспонента, а при переборе перестановок будет факториал.
        */
        
        generate(n);
        return pairs;
    }

private:
    vector<string> pairs;
    vector<char> pair;
    
    int begin_count = 0;
    int end_count = 0;
    
    bool correct_sequence(const int& n) {
        return begin_count >= end_count 
            && begin_count <= n && end_count <= n;
    }
    
    void generate(const int& n) {
        
        if (!correct_sequence(n)) return;
        
        if (pair.size() == 2 * n) {
            string seq(begin(pair), end(pair));
            pairs.push_back(seq);
        }
        else {
            
            pair.push_back('(');
            begin_count++;
            generate(n);
            pair.pop_back();
            begin_count--;
            
            pair.push_back(')');
            end_count++;
            generate(n);
            pair.pop_back();
            end_count--;
        }
    }
};