/*
1006. 求和游戏
Description
石柱上有一排石头键盘，每个键上有一个整数。请你在键盘上选择两个键，使这两个键及其之间的键上的数字和最大。如果这个最大的和不为正，则输出“Game Over"。

Input Format
第1行：键的个数n。

第2..n+1行：键上的数字整数 ai。

−100≤ai≤100
对于70%的数据，2≤n≤1,000
对于100%的数据，2≤n≤1,000,000
Output Format
一行，最大和或者”Game Over"。

Sample Input
5
3
-5
7
-2
8
Sample Output
13
Sample Input
3
-6
-9
-10
Sample Output
Game Over
Hints
数据得到了增强！

感谢 曹宇 <caoyu601 at live.com>
感谢 Rozc <i at rozc.farm>
*/
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n, i, M = -1;
    scanf("%d", &n);
    int a[n], sum[n];
    for (i=0; i<n; ++i) {
        scanf("%d", &a[i]);
    }
    sum[0] = 0; sum[1] = a[0] + a[1]; M = sum[1];
    for (i=2; i<n; ++i) {
        if (a[i-1]+a[i] > sum[i-1]+a[i]) sum[i] = a[i-1] + a[i];
        else sum[i] = sum[i-1] + a[i];
        if (sum[i] > M) M = sum[i];
    }
    if (M > 0) printf("%d", M);
    else printf("Game Over\n");
    return 0;
}
