//
// Created by rbcheng on 19-5-14.
// Email: rbcheng@qq.com
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> each_month_days_common = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> each_month_days_leap = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
    auto sum_month_days_common = each_month_days_common;
    auto sum_month_days_leap = each_month_days_leap;

    for (int i = 1; i <= 12; i++) {
        sum_month_days_common[i] += sum_month_days_common[i-1];
        sum_month_days_leap[i] += sum_month_days_leap[i-1];
    }

    int year, month, day;

    while (cin>>year>>month>>day) {

        if (((year%4) == 0 && (year%100) != 0) || ((year%400) == 0)) {
            cout << sum_month_days_leap[month - 1] + day << endl;
        } else {
            cout << sum_month_days_common[month - 1] + day << endl;
        }
    }
}