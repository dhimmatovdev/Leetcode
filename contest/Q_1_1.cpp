#include <iostream>
using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {
        // Pattern ichida '*' belgisini topamiz
        size_t starPos = p.find('*');
        if (starPos == string::npos) return false;

        // 'left' va 'right' qismlarini aniqlaymiz
        string left = p.substr(0, starPos);
        string right = p.substr(starPos + 1);

        // 'left' qismi stringning boshida mos kelishini tekshirish
        if (s.substr(0, left.size()) != left) return false;

        // 'right' qismi stringning oxirida mos kelishini tekshirish
        if (s.substr(s.size() - right.size()) != right) return false;

        // Agar ikkala qism ham mos kelsa, true qaytaramiz
        return true;
    } 
};
int main() {
    Solution solution;

    // Oddiy testlar
    cout << (solution.hasMatch("leetcode", "ee*e") ? "true" : "false") << endl; // true
    cout << (solution.hasMatch("car", "c*v") ? "true" : "false") << endl;       // false
    cout << (solution.hasMatch("luck", "u*") ? "true" : "false") << endl;       // true

    // Chekka holatlar
    cout << (solution.hasMatch("abc", "a*b") ? "true" : "false") << endl;       // true
    cout << (solution.hasMatch("abc", "*c") ? "true" : "false") << endl;        // true
    cout << (solution.hasMatch("abc", "*d") ? "true" : "false") << endl;        // false
    cout << (solution.hasMatch("", "*") ? "true" : "false") << endl;            // true

    return 0;
}



