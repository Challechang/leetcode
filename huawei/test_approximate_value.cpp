//
// Created by rbcheng on 19-5-14.
// Email: rbcheng@qq.com
//

#include <iostream>
using namespace std;

int main() {

    float num;
    while (cin >> num) {
        float diff = num - int(num);
        if (diff >= 0.5) {
            cout << int(num) + 1<< endl;
        } else {
            cout << int(num) << endl;
        }
    }
}