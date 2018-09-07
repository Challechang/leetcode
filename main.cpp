#include <iostream>
#include "Solution.h"

int main() {
    Solution *solution = new Solution();
//    std::cout << solution->multiply("123", "456") << std::endl;
//    std::cout << solution->addStrings("123456789", "987654321") << std::endl;
//    for (int i = 0; i < 10; ++i) {
//        solution->generate(i);
//    }
        std::vector<int> nums1;
        nums1.push_back(1);
        nums1.push_back(2);
        nums1.push_back(3);
        nums1.push_back(0);
        nums1.push_back(0);
        nums1.push_back(0);
        std::vector<int> nums2;
        nums2.push_back(2);
        nums2.push_back(5);
        nums2.push_back(6);
        solution->merge(nums1, 3, nums2, 3);

    delete solution;
}