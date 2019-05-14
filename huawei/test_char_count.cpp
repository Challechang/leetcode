//
// Created by rbcheng on 19-5-14.
// Email: rbcheng@qq.com
//

#include <iostream>
#include <array>

using namespace std;

int main() {

    string str;
    while (cin>>str) {

        int count = 0;
        array<bool, 128> exists;
        exists.fill(false);

        for (int i = 0; i < str.size(); ++i) {
            if (str[i] >= 0 && str[i] <= 127&&!exists[str[i]]) {
                count ++;
                exists[str[i]] = true;
            }
        }
        cout << count << endl;
    }
}