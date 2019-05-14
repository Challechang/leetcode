//
// Created by Administrator on 2017/7/13.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){};
};

class Solution {
public:
    // 43. Multiply Strings
    std::string multiply(std::string num1, std::string num2);
    // 415. Add Strings
    std::string addStrings(std::string num1, std::string num2);
    // 141. Linked List Cycle 感觉这道题目有bug
    bool hasCycle(ListNode *head);
    void swap(std::string &num1, std::string &num2);
    void reverse_str(std::string &str);

    // 118. 杨辉三角I
    std::vector<std::vector<int>> generate(int numRows);
    // 119. 杨辉三角II
    std::vector<int> getRow(int rowIndex);
    // 88. 合并两个有序数组
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);
    // 867. 转置矩阵
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& A);
    // 566. 重塑矩阵
    std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& nums, int r, int c);
    // 766. 托普利茨矩阵
    bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix);
    // 283. 移动零
    void moveZeroes(std::vector<int>& nums);
    // 78. 子集
    std::vector<std::vector<int>> subsets(std::vector<int>& nums);
    // 414. 第三大的数
    int thirdMax(std::vector<int>& nums);
};


#endif //LEETCODE_SOLUTION_H
