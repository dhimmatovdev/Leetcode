#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<string> uniquePalindromes; // Palindromlarni saqlash uchun
        unordered_set<char> leftChars;          // Chap tomon belgilari
        vector<int> rightCount(26, 0);          // O'ng tomon belgilari soni

        // O'ngdagi har bir belgi sonini hisoblash
        for (char c : s) {
            rightCount[c - 'a']++;
        }

        // Har bir belgi uchun chap va o‘ng tomonlarni tekshirish
        for (int i = 0; i < n; i++) {
            char currentChar = s[i];
            rightCount[currentChar - 'a']--; // Joriy belgini o'ngdan olib tashlash

            // Chap va o‘ng tomonlardan palindromni qidirish
            for (char c = 'a'; c <= 'z'; c++) {
                if (leftChars.count(c) && rightCount[c - 'a'] > 0) {
                    string palindrome = string(1, c) + currentChar + string(1, c);
                    uniquePalindromes.insert(palindrome);
                }
            }

            // Joriy belgini chapga qo‘shish
            leftChars.insert(currentChar);
        }

        return uniquePalindromes.size(); // Palindromlar soni
    }
};

int main() {
    Solution solution;
    string s = "bbcbaba";
    cout << "Unique Length-3 Palindromic Subsequences: " 
         << solution.countPalindromicSubsequence(s) << endl;
    return 0;
}
