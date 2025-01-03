#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // 1. Vektorni Bubble Sort orqali tartibga keltirish
        sort(nums.begin(), nums.end());
        
        // 2. Kichik elementlarni yig‘ish
        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }

        return sum;
    }
};

int main() {
    Solution solution;

    // Vektorni e'lon qilish
    vector<int> nums = {6, 2, 6, 5, 1, 2};

    // Natijani chiqarish
    cout << "Natija: " << solution.arrayPairSum(nums) << endl;

    return 0;
}
