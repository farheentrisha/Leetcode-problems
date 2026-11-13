
class Solution {
public:
    int romanToInt(string s) {

        // Store the value of each Roman symbol
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;

        for (int i = 0; i < s.length(); i++) {

            // If current value is smaller than the next value,
            // subtract it (e.g., IV = 5 - 1)
            if (i + 1 < s.length() && roman[s[i]] < roman[s[i + 1]]) {
                result -= roman[s[i]];
            }
            else {
                // Otherwise, add the current value
                result += roman[s[i]];
            }
        }

        return result;
    }
};

