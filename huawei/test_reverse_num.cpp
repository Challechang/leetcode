//
// Created by rbcheng on 19-5-14.
// Email: rbcheng@qq.com
//

#include <iostream>

using namespace std;

int main() {

    int num;
    while (cin>>num) {
        string str_num = to_string(num);

        for (auto it = str_num.rbegin(); it != str_num.rend(); ++it) {
            cout << *it ;
        }
        cout << endl;
    }
}