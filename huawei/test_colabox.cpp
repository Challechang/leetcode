//
// Created by rbcheng on 19-5-14.
// Email: rbcheng@qq.com
//

#include <iostream>
using namespace std;

int main() {

    int n;

    int count_empty_box;
    while (cin >> count_empty_box) {
        int count_can_drink = 0;
        if (count_empty_box == 0) {
            break;
        }

        if (count_empty_box == 1) {
            cout << count_can_drink << endl;
            continue;
        }

        if (count_empty_box == 2) {
            cout << ++count_can_drink << endl;
            continue;
        }

        cout << count_empty_box / 2 << endl;
    }

}
