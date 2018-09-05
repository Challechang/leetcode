#include <iostream>
#include "Solution.h"

int main() {
    Solution *solution = new Solution();
//    std::cout << solution->multiply("123", "456") << std::endl;
//    std::cout << solution->addStrings("123456789", "987654321") << std::endl;
    for (int i = 0; i < 10; ++i) {
        solution->generate(i);
    }

    delete solution;
}