#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> prefix_diff(s.length() + 1, 0);

        // Prefix difference massivini to'ldirish
        for (const auto& shift : shifts) {
            int left = shift[0], right = shift[1], d = shift[2];
            prefix_diff[right + 1] += (d ? 1 : -1);
            prefix_diff[left] += (d ? -1 : 1);
        }

        // Harflarni o'zgartirish
        int diff = 0;
        vector<int> res(s.length());
        for (int i = 0; i < s.length(); ++i) {
            res[i] = s[i] - 'a';
        }

        for (int i = s.length(); i >= 1; --i) {
            diff += prefix_diff[i];
            res[i - 1] = (res[i - 1] + diff) % 26;
            if (res[i - 1] < 0) {
                res[i - 1] += 26; // Salbiy qiymatlarni ijobiyga aylantirish
            }
        }

        // Natijani yig'ish
        for (int i = 0; i < s.length(); ++i) {
            s[i] = 'a' + res[i];
        }

        return s;
    }
};

int main() {
    Solution sol;
    string s = "abc";
    vector<vector<int>> shifts = {{0, 1, 1}, {1, 2, 0}};
    cout << sol.shiftingLetters(s, shifts) << endl;
    return 0;
}
