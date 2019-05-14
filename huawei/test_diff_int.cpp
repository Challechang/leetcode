//
// Created by rbcheng on 19-5-14.
// Email: rbcheng@qq.com
//

#include <iostream>
#include <array>
using namespace std;

int main() {

    int num;

    while (cin>>num) {

        array<bool, 10> exists;
        for (int i = 0; i < exists.size(); ++i) {
            exists[i] = false;
        }
        string str_num = to_string(num);
        string str_result;
        for (auto it = str_num.rbegin(); it != str_num.rend(); ++it) {
            auto ch = *it;
            if (!exists[ch - '0']) {
                str_result.push_back(ch);
                exists[ch - '0'] = true;
            }
        }
        cout << stoi(str_result) << endl;
    }
}