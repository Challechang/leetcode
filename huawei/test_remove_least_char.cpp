//
// Created by rbcheng on 19-5-14.
// Email: rbcheng@qq.com
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main () {

    string str;
    while (cin>>str) {

        unordered_map<char, int> char_map;
        for (int i = 0; i < str.size(); ++i) {
            if (char_map.find(str[i]) != char_map.end()) {
                ++char_map[str[i]];
            } else {
                char_map[str[i]] = 1;
            }
        }

        int min = INT32_MAX;
        for (auto& char_pair: char_map) {
            if (char_pair.second < min) {
                min = char_pair.second;
            }
        }
        unordered_set<char> char_set;

        for (auto& char_pair: char_map) {
            if (char_pair.second == min) {
                char_set.insert(char_pair.first);
            }
        }

        string result;
        for (int j = 0; j < str.size(); ++j) {
            if (char_set.find(str[j]) == char_set.end()) {
                result.push_back(str[j]);
            }
        }
        cout << result << endl;
    }
}