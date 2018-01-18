/*
1002. 二哥种花生
Description
二哥在自己的后花园里种了一些花生，也快到了收获的时候了。这片花生地是一个长度为L、宽度为W的矩形，每个单位面积上花生产量都是独立的。他想知道，对于某个指定的区域大小，在这么大的矩形区域内，花生的产量最大会是多少。

Input Format
第1行有2个整数，长度L和宽度W。

第2行至第L+1行，每行有W个整数，分别表示对应的单位面积上的花生产量A（ 0≤A<10 ）。

第L+2行有2个整数，分别是指定的区域大小的长度a和宽度b。

Output Format
输出一个整数m，表示在指定大小的区域内，花生最大产量为m。

Sample Input
4 5
1 2 3 4 5
6 7 8 0 0
0 9 2 2 3
3 0 0 0 1
3 3
Sample Output
38
样例解释
左上角：38 = (1+2+3) + (6+7+8) + (0+9+2)

数据范围
对于30%的数据： 1≤L,W≤100；

对于100%的数据： 1≤L,W≤1000。

全部区域大小满足：1≤a≤L，1≤b≤W 。
*/
#include <iostream>
using namespace std;

int main()
{
    int L, W, i, j, a, b, m = -1;
    cin >> L >> W;
    int **A;
    A = new int *[L];
    for (i=0; i<L; ++i) A[i] = new int [W];
    for (i=0; i<L; ++i) {
        for (j=0; j<W; ++j) {
            cin >> A[i][j];
        }
    }
    cin >> a >> b;
    int **M;
    int height = L - a + 1, width = W - b + 1, tmp = 0, k;
    M = new int *[height];
    for (i=0; i<height; ++i) M[i] = new int [width];
    for (i=0; i<a; ++i) {
        for (j=0; j<b; ++j) {
            tmp += A[i][j];
        }
    }
    M[0][0] = tmp;
    m = M[0][0];
    for (i=1; i<width; ++i) {
        for (j=0; j<a; ++j) {
            tmp -= A[j][i-1];
            tmp += A[j][i+b-1];
        }
        M[0][i] = tmp;
        if (M[0][i] > m) m = M[0][i];
    }
    for (i=1; i<height; ++i) {
        for (j=0; j<width; ++j) {
            tmp = M[i-1][j];
            for (k=0; k<b; ++k) {
                tmp -= A[i-1][j+k];
                tmp += A[i+a-1][j+k];
            }
            M[i][j] = tmp;
            if (M[i][j] > m) m = M[i][j];
        }
    }
    cout << m;
    return 0;
}
