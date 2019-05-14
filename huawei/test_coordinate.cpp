//
// Created by rbcheng on 19-5-14.
// Email: rbcheng@qq.com
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> cal_coordinate(string& input) {
    vector<int> coordinate = {0, 0};

    for (int i = 0; i < input.size();) {
        while (i < input.size() && input[i] == ';') {
            i++;
        }

        if (i == input.size()) {
            continue;
        }

        int first = 0, second = 0;
        string sub;
        while (i < input.size() && input[i] != ';') {
            sub.push_back(input[i]);
            i++;
        }
        if (sub.size() > 3 || sub.size() <= 1) {
            continue;
        }

        bool legal = true;
        for (int j = 1; j < sub.size(); ++j) {
            if (sub[j] >= '0' && sub[j] <= '9') {
                continue;
            } else {
                legal = false;
            }
        }
        if (!legal) {
            continue;
        }

        if (sub[0] != 'A' && sub[0] != 'W' && sub[0] != 'S' && sub[0] != 'D') {
            continue;
        }

        string str_offset = sub.substr(1, sub.size() - 1);
        auto offset = stoi(str_offset);

        switch (sub[0]) {
            case 'W':
                second = offset;
                break;
            case 'S':
                second = offset * -1;
                break;
            case 'A':
                first = offset * -1;
                break;
            case 'D':
                first = offset;
                break;
        }
        coordinate[0] += first;
        coordinate[1] += second;
    }
    return coordinate;
}

int main() {

    string str;

    while (getline(cin, str)) {
        auto coordinate = cal_coordinate(str);
        cout << coordinate[0] << "," << coordinate[1] << endl;
    }

}
