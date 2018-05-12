/*
1009. 二哥炒股票
题目描述
二哥需要一个能根据交易记录和股票价格记录统计出先进收益的程序。

现金收益包括两部分，一部分是卖出收入，一部分是每次交易需要支出的费用。卖出收入就是卖出股票获得的总收入减去买入的总支出。股票的价格是按每股的价格给出的，而交易的最小单位是“一手”，每手是100股。每次买入的费用如下所述：

1.佣金，收取交易额的0.2%，但最低的收取标准是5元。比如买入总金额为1000元的股票，实际佣金是2元，但不超过5元，所以按5元收取。

2.过户费，每一千股收取1元。

3.通讯费，由于二哥在上海，每次只收取本地交易费用1元。

每次卖出的费用标准与买入一致，但还要加收证券印花税（交易额的0.1%）。

另外，二哥是个专一的人，他只对一支股票感兴趣。

输入格式
输入分为两部分，第一部分是二哥的交易记录，第二部分是股票价格记录。

交易记录的第一行是一个正整数m，表示共有m个交易动作。每个交易动作占一行，包括三个正整数t, a和d, d = 1时，表示在时间t买入该股票a手，当d = 2时，表示在时间t卖出该股票a手。记录信息保证有意义;d不会取其他值。

股票价格记录的第一行是一个正整数n，表示共有n次价格变动。每次价格变动占一行，包括两个正整数t和v,表示在时间t该股票的价格变为v元每股。价格变动过程是按时间顺序给出的，第一次价格变动之前不会发生交易；t使用的是一个虚拟的时间量度，在时间t进行的交易按价格v计算。

输出格式
输出二哥的现金收益，保留两位小数（四舍五入）。

说明
对于所有数据：m≤50, v≤200, a≤200
对于70%的数据：n≤100 , t≤10000
对于30%的数据：n≤10000 , t≤100000000
Sample Input
2
15 50 1
40 30 2
4
10 100
20 90
30 95
40 102
Sample Output
-195928.00
*/
#include <iostream>
#include <stdio.h>
using namespace std;

double sell(int price, int number)
{
    double trade_amount = number * price;
    int positive_num = (number>0) ? number : (-number);
    double yinhua = (trade_amount>0) ? (trade_amount*0.001) : 0;
    double yongjin = (positive_num*price*0.002>5) ? (positive_num*price*0.002) : 5;
    double guohu = positive_num * 1.0 / 1000;
    double tongxun = 1;
    return (trade_amount-yinhua-yongjin-guohu-tongxun);
}

double trade(int** opt, int** price, int m, int n)
{
    int tmp_o = 0, tmp_p = 1;
    int pr = price[0][1]; //price at beginning
    double gain = 0;
    while (tmp_o < m) {
        int n_act = (opt[tmp_o][2]==1) ? (-opt[tmp_o][1]*100) : (opt[tmp_o][1]*100); //how many be bought in the beginning
        if (tmp_p>=n || opt[tmp_o][0]<price[tmp_p][0]) {
            gain += sell(pr, n_act);
            tmp_o += 1;
        }
        else {
            pr = price[tmp_p][1];
            tmp_p += 1;
        }
    }
    return gain;
}

int main()
{
    int m, i, n;
    scanf("%d", &m);
    int **opt;
    opt = new int *[m];
    for (i=0; i<m; ++i) {
        opt[i] = new int[3];
        scanf("%d%d%d", &opt[i][0], &opt[i][1], &opt[i][2]);
    }
    scanf("%d", &n);
    int **price;
    price = new int *[n];
    for (i=0; i<n; ++i) {
        price[i] = new int[2];
        scanf("%d%d", &price[i][0], &price[i][1]);
    }
    double gain = trade(opt, price, m, n);
    printf("%.2f\n", gain);
    return 0;
}
