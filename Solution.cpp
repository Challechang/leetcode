//
// Created by Administrator on 2017/7/13.
//

#include "Solution.h"

void Solution::reverse_str(std::string &str) {
    int len = str.size();
    for (int i = 0; i < len/2; i++ ) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void Solution::swap(std::string &num1, std::string &num2) {
    std::string t = num1;
    num1 = num2;
    num2 = t;
}

std::string Solution::multiply(std::string num1, std::string num2) {
    std::string result = "";
    int num1_len = num1.size(), num2_len = num2.size(), sum_len = num1_len + num2_len;
    int *result_temp = new int[sum_len];
    int *num1_temp = new int[num1_len];
    int *num2_temp = new int[num2_len];
    // init int array result_temp
    for (int i = 0; i < sum_len; i++)
        result_temp[i] = 0;
    // reverse string num1 and num2
    reverse_str(num1), reverse_str(num2);
    for (int i = 0; i < num1_len; i++)
        num1_temp[i] = num1[i] - '0';
    for (int i = 0; i < num2_len; i++)
        num2_temp[i] = num2[i] - '0';
    int i = 0, j = 0;
    // multipy num1 and num2, and store result in int array result_temp
    for (int i = 0; i < num1_len; i++)
        for (int j = 0; j < num2_len; j++) {
            result_temp[i + j] += num1_temp[i] * num2_temp[j];
        }
    // carry
    int temp = 0;
    for (int i = 0; i < sum_len; i++) {
        int t = result_temp[i] + temp;
        result_temp[i] = t % 10;
        temp = t / 10;
    }
    for (int i = 0; i < sum_len; i++) {
        result.insert(0, std::to_string(result_temp[i]));
    }
    while(1) {
        if (result[0] == '0' && result.size() > 1)
            result.erase(result.begin());
        else
            break;
    }
    return result;
}

std::string Solution::addStrings(std::string num1, std::string num2) {
    std::string result = "";
    if (num2.size() > num1.size())
        swap(num1, num2);
    int num1_len = num1.size(), num2_len = num2.size();
    int *num1_temp = new int[num1_len];
    int *num2_temp = new int[num2_len];
    int *result_temp = new int[num1_len + 1];
    reverse_str(num1), reverse_str(num2);
    // init int array result_temp, num1_temp, num2_temp
    for (int i = 0; i < num1_len + 1; i++)
        result_temp[i] = 0;
    for (int i = 0; i < num1_len; i++)
        num1_temp[i] = num1[i] - '0';
    for (int i = 0; i < num2_len; i++)
        num2_temp[i] = num2[i] - '0';
    // add num1 and num2, result store in result_temp
    for (int i = 0; i < num2_len; i++)
        result_temp[i] = num1_temp[i] + num2_temp[i];
    for (int i = num2_len; i < num1_len; i++)
        result_temp[i] = num1_temp[i];
    // carray
    int temp = 0;
    for (int i = 0; i < num1_len; i++) {
        int t = result_temp[i] + temp;
        result_temp[i] = t % 10;
        temp = t / 10;
    }
    result_temp[num1_len] = temp;
    // convert result to string array from int array
    for (int i = 0; i < num1_len + 1; i++)
        result.insert(0, std::to_string(result_temp[i]));
    // delete surplus 0
    while (1) {
        if (result[0] == '0' && result.size() > 1)
            result.erase(result.begin());
        else
            break;
    }

    delete []num1_temp;
    delete []num2_temp;
    delete []result_temp;
    return result;
}

bool Solution::hasCycle(ListNode *head) {
    // 使用快慢指针
    ListNode *fast = head, *slow = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}
