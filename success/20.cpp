class Solution {
public:
    bool isValid(string s) {
        
        if (s.size() == 1) return false;
        
        map<char, char> brackets = {
            { ')', '(' },
            { '}', '{' },
            { ']', '[' },
        };
        
        vector<char> stack;
        for (const auto& c : s) {
            if (brackets.count(c) == 0) {
                stack.push_back(c);
            }
            else if (stack.size() != 0) {
                char peek = stack.back();
                stack.pop_back();
                if (peek != brackets[c]) return false;
            }
            else return false;
            
        }
        
        return stack.size() == 0;
    }
};