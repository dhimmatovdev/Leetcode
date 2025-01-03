#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // 1. Vektorni Bubble Sort orqali tartibga keltirish
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = 0; j < nums.size() - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    // Joylarini almashtirish
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
        
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
