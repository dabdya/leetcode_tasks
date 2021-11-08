class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return { };
        }
        
        search(0, digits);
        return combinations;
    }

private:
    vector<string> combinations;
    vector<char> combination;
    map<char, vector<char>> phone_letters = {
        { '2', { 'a', 'b', 'c' } },
        { '3', { 'd', 'e', 'f' } },
        { '4', { 'g', 'h', 'i' } },
        { '5', { 'j', 'k', 'l' } },
        { '6', { 'm', 'n', 'o' } },
        { '7', { 'p', 'q', 'r', 's' } },
        { '8', { 't', 'u', 'v' } },
        { '9', { 'w', 'x', 'y', 'z' } },
    };
    
    void search(int i, string& digits) {
        
        if (combination.size() == digits.size()) {
            string comb_str(begin(combination), end(combination));
            combinations.push_back(comb_str);
        }
        else {
            
            for (const auto& letter : phone_letters[digits[i]]) {
                combination.push_back(letter);
                search(i + 1, digits);
                combination.pop_back();
            } 
        }
        
    }
};