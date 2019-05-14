//
// Created by rbcheng on 19-5-14.
// Email: rbcheng@qq.com
//

#include <iostream>
#include <map>

using namespace std;

int main() {

    int n;
    while (cin>>n) {
        map<int, int> records;
        while (n--) {
            int first, second;
            cin>>first>>second;
            if (records.find(first) != records.end()) {
                records[first] += second;
            } else {
                records[first] = second;
            }
        }

        for (auto& record: records) {
            cout << record.first << " "<< record.second << endl;
        }
    }
}