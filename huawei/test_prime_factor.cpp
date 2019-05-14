//
// Created by rbcheng on 19-5-14.
// Email: rbcheng@qq.com
//

#include <iostream>

using namespace std;

string getResult(long input) {
    string result;
    if (input < 2) {
        return result;
    }

    for (int i = 2; i <= input; ++i) {

        while (input % i == 0) {
            input = input / i;
            auto temp = std::to_string(i) + " ";
            result.append(temp);
        }
    }

    return result;
}

int main() {

    long input;

    while (cin>>input) {

        cout << getResult(input) <<endl;
    }

}