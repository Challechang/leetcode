//
// Created by rbcheng on 19-5-14.
// Email: rbcheng@qq.com
//

#include <iostream>

using namespace std;

int main() {

    int num;
    while (cin>>num) {

        int count = 0;
        while (num) {
            if (num % 2 == 1) {
                ++count;
            }
            num = num >> 1;
        }
        cout << count << endl;
    }
}