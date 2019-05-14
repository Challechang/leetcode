//
// Created by rbcheng on 19-5-14.
// Email: rbcheng@qq.com
//

#include <iostream>

using namespace std;

int main() {

    string str;
    while (cin>>str) {

        string password;

        for (int i = 0; i < str.size(); ++i) {
            if (str[i] >= '0' && str[i] <= '9') {
                password.push_back(str[i]);
                continue;
            }

            if (str[i] >= 'A' && str[i] <= 'Z') {
                auto lower = tolower(str[i]);
                if (lower == 'z') {
                    lower = 'a';
                } else {
                    lower++;
                }
                password.push_back(lower);
                continue;
            }

            if (str[i] >= 'a' && str[i] <= 'z') {

                if (str[i] >= 'a' && str[i] <= 'c') {
                    password.push_back('2');
                } else if (str[i] >= 'd' && str[i] <= 'f') {
                    password.push_back('3');
                } else if (str[i] >= 'g' && str[i] <= 'i') {
                    password.push_back('4');
                } else if (str[i] >= 'j' && str[i] <= 'l') {
                    password.push_back('5');
                } else if (str[i] >= 'm' && str[i] <= 'o') {
                    password.push_back('6');
                } else if (str[i] >= 'p' && str[i] <= 's') {
                    password.push_back('7');
                } else if (str[i] >= 't' && str[i] <= 'v') {
                    password.push_back('8');
                } else if (str[i] >= 'w' && str[i] <= 'z') {
                    password.push_back('9');
                }

                continue;
            }
            password.push_back(str[i]);
        }
        cout << password << endl;
    }

}