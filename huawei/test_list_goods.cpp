//
// Created by rbcheng on 19-5-15.
// Email: rbcheng@qq.com
//

#include <iostream>
#include <array>
#include <vector>
using namespace std;

#define MAX_GOODS_NUM 61
#define MAX_GOODS_PRICE 32010

struct Good {
    int price;
    int importance;
    int number;
};

int max_sum(vector<Good>& goods, int total_money, int goods_num) {
    int dp[MAX_GOODS_NUM][MAX_GOODS_PRICE];
    for (int i = 0; i < MAX_GOODS_NUM; ++i) {
        for (int j = 0; j < MAX_GOODS_PRICE; ++j) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= goods_num ; ++i) {
        for (int j = 1; j <= total_money ; ++j) {

            if (goods[i].price > j) {
//                dp[i][j] = dp[i-1][j];
            } else {
                if (goods[i].number == 0) {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-goods[i].price] + (goods[i].price*goods[i].importance));
                } else {
                    if (goods[i].price + goods[goods[i].number].price <= j) {
                        dp[i][j] = max(dp[i-1][j], dp[i-1][j-goods[i].price] + (goods[i].price*goods[i].importance));
                    }
                }
            }
        }
    }
    return dp[goods_num][total_money];
}

int main() {

    int N, m;

    while (cin>>N>>m) {
        m++;
        vector<Good> goods;
        goods.insert(goods.begin(), m, Good());
        for (int i = 1; i < m; ++i) {
            cin>>goods[i].price>>goods[i].importance>>goods[i].number;
        }

        cout << max_sum(goods, N, m-1) << endl;
    }
}