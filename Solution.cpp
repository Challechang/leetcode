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

std::vector<std::vector<int>> Solution::generate(int numRows) {
    std::vector< std::vector<int> > result;
    for (int i = 1; i <= numRows; ++i) {
        std::vector<int> line;
        if (i == 1) {
            line.push_back(1);
        } else {
            line.push_back(1);

            int first = 1, last = i;
            for (int j = first + 1; j < last; ++j) {
                std::vector<int> pre_line = result.at(i - 2);
                int num1 = pre_line.at(j - 2), num2 = pre_line.at(j - 1);
                line.push_back(num1 + num2);
            }

            line.push_back(1);
        }
        result.push_back(line);
    }

    return result;
}

std::vector<int> Solution::getRow(int rowIndex) {
    std::vector<int> next_line;
    std::vector<int> pre_line;
    pre_line.push_back(1);
    next_line.push_back(1);
    next_line.push_back(1);
    if (rowIndex == 0) {
        return pre_line;
    }

    if (rowIndex == 1) {
        return next_line;
    }

    for (int i = 1; i < rowIndex; ++i) {
        pre_line.clear();
        std::copy(next_line.begin(), next_line.end(), std::back_inserter(pre_line));
        next_line.clear();
        next_line.push_back(1);

        for (int j = 1; j < i + 1; ++j) {
            next_line.push_back(pre_line.at(j) + pre_line.at(j - 1));
        }
        next_line.push_back(1);
    }

    return next_line;

}

void Solution::merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    std::vector<int> result;
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (nums1.at(i) < nums2.at(j)) {
            result.push_back(nums1.at(i));
            i++;
        } else {
            result.push_back(nums2.at(j));
            j++;
        }
    }

    while (i < m) {
        result.push_back(nums1.at(i));
        i++;
    }

    while (j < n) {
        result.push_back(nums2.at(j));
        j++;
    }
    nums1.clear();
    for (int k = 0; k < result.size(); ++k) {
        nums1.push_back(result.at(k));
    }
}

std::vector<std::vector<int>> Solution::transpose(std::vector<std::vector<int>>& A) {
    std::vector<std::vector<int>> result;
    if (A.size() == 0 || A.at(0).size() == 0) {
        return result;
    }
    int result_cols = A.at(0).size();
    for (int i = 0; i < result_cols; ++i) {
        result.push_back(std::vector<int>());
    }
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A.at(i).size(); ++j) {
            result.at(j).push_back(A.at(i).at(j));
        }
    }

    return result;
}

std::vector<std::vector<int>> Solution::matrixReshape(std::vector<std::vector<int>> &nums, int r, int c) {
    if (nums.size() == 0 || nums.at(0).size() == 0) {
        return nums;
    }
    int nums_rows = nums.size(), nums_cols = nums.at(0).size();
    if ((nums_cols * nums_rows) != (r * c)) {
        return nums;
    }
    std::vector<std::vector<int>> result;
    for (int i = 0; i < r; ++i) {
        result.emplace_back(std::vector<int>());
    }
    int result_rows_index = 0, result_cols_index = 0;
    for (int i = 0; i < nums_rows; ++i) {
        for (int j = 0; j < nums_cols; ++j) {
            result.at(result_rows_index).emplace_back(nums.at(i).at(j));
            result_cols_index++;
            if (result_cols_index == c) {
                result_rows_index++;
                result_cols_index = 0;
            }
        }
    }
    return result;

}

bool Solution::isToeplitzMatrix(std::vector<std::vector<int>> &matrix) {
    bool result = true;
    int rows = matrix.size(), cols = matrix.at(0).size();
    if (rows == 1 && cols == 1) {
        return true;
    }

    if ((rows == 1 && cols > 1) || (rows > 1 && cols == 1)) {
        return result;
    }
    int first_num, rows_index, cols_index;

    for (int i = 1; i < rows; ++i) {
        first_num = matrix.at(i).at(0);
        rows_index = i;
        cols_index = 0;
        while (rows_index < rows && cols_index < cols) {
            if (first_num != matrix.at(rows_index).at(cols_index)) {
                return !result;
            }
            rows_index++;
            cols_index++;
        }
    }

    for (int i = 0; i < cols; ++i) {
        first_num = matrix.at(0).at(i);
        rows_index = 0;
        cols_index = i;
        while (rows_index < rows && cols_index < cols) {
            if (first_num != matrix.at(rows_index).at(cols_index)) {
                return !result;
            }
            rows_index++;
            cols_index++;
        }
    }
    return result;
}

void Solution::moveZeroes(std::vector<int> &nums) {
    int nums_size = nums.size();
    if (nums_size <= 1) {
        return;
    }

    int index = nums_size - 1;

    // filter zero which in the tail of array
    for (; index >= 0 ; --index) {
        if (nums[index] != 0) {
            break;
        }
    }

    for (; index >= 0 ; --index) {
        if (nums[index] == 0) {
            nums.erase(nums.begin() + index);
            nums.emplace_back(0);
        }
    }
}

std::vector<std::vector<int>> Solution::subsets(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;

}

int Solution::thirdMax(std::vector<int> &nums) {

}
