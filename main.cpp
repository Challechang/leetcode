#include <iostream>
#include "Solution.h"

int main() {
    Solution *solution = new Solution();
//    std::cout << solution->multiply("123", "456") << std::endl;
//    std::cout << solution->addStrings("123456789", "987654321") << std::endl;
    // 118. 杨辉三角I
//    for (int i = 0; i < 10; ++i) {
//        solution->generate(i);
//    }
    // 88. 合并两个有序数组
//        std::vector<int> nums1;
//        nums1.push_back(1);
//        nums1.push_back(2);
//        nums1.push_back(3);
//        nums1.push_back(0);
//        nums1.push_back(0);
//        nums1.push_back(0);
//        std::vector<int> nums2;
//        nums2.push_back(2);
//        nums2.push_back(5);
//        nums2.push_back(6);
//        solution->merge(nums1, 3, nums2, 3);
//    // 119. 杨辉三角II
//    for (int i = 0; i < 10; ++i) {
//        solution->getRow(i);
//    }
    // 566. 重塑矩阵
            std::vector<std::vector<int>> nums;
            nums.emplace_back(std::vector<int>());
            nums.emplace_back(std::vector<int>());
            nums.at(0).emplace_back(1);
            nums.at(0).emplace_back(2);
            nums.at(1).emplace_back(3);
            nums.at(1).emplace_back(4);
            int r = 1, c = 4;
            solution->matrixReshape(nums, r, c);

    delete solution;
}