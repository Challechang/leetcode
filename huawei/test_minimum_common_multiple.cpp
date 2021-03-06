//
// Created by rbcheng on 19-5-15.
// Email: rbcheng@qq.com
//

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }

    return gcd(b, a%b);
}

int main() {
    int a, b;
    while (cin>>a>>b) {

        cout << a*b/gcd(a, b) << endl;
    }
}