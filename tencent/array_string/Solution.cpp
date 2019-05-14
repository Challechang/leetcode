//
// Created by rbcheng on 18-9-14.
// Email: rbcheng@qq.com
//

#include "Solution.h"

namespace tencent {
    namespace array_string {

        std::vector<int> Solution::twoSum(std::vector<int> &nums, int target) {
            std::unordered_map<int, int> nums_map;
            int size = nums.size();
            for (int i = 0; i < size; ++i) {
                nums_map[nums[i]] = i;
            }
            std::vector<int> result;
            for (int first_index = 0; first_index < size; ++first_index) {
                int need_num = target - nums[first_index];
                int second_index;
                if (nums_map.find(need_num) != nums_map.end()) {
                    second_index = nums_map[need_num];
                    if (second_index == first_index) {
                        continue;
                    }
                    result.emplace_back(first_index);
                    result.emplace_back(second_index);
                    break;
                }
            }

            return result;
        }
    }
}