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

    // 118. 杨辉三角
    std::vector<std::vector<int>> generate(int numRows);
};


#endif //LEETCODE_SOLUTION_H
