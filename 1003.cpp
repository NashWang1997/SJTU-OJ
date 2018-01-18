/*
1003. 二哥养细菌
题目描述
二哥不仅种苹果和花生，还养了很多细菌。二哥的细菌培养皿成方格形，边长为L。长期培养后，二哥发现了细菌繁殖的规律：最初每个格子里的细菌及其后代都会独立繁殖，每次繁殖都会在其上下左右四个相邻的格子里产生新的细菌，而已经存在的细菌在培养皿充满细菌之前都不会死亡。另外，有一些格子里可能还有抗生素，细菌在有抗生素的格子里无法繁殖。

二哥于是发明了一个游戏：取一个新的培养皿，在某些格子里放入细菌或抗生素，然后观察细菌不断繁殖直至充满整个培养皿的所有没有抗生素的格子。不过二哥已经对这个游戏厌烦了，他现在只想知道经过多少轮繁殖后，细菌会充满整个培养皿（不算有抗生素的格子）。

输入格式
第1行有1个整数，边长L。

第2行至第L+1行，每行有L个整数，取值为0、1或2。0表示格子里最初没有细菌，1表示格子里最初有细菌，2表示格子里最初有抗生素。

输出格式
输出一个整数m，表示经过m轮繁殖后，细菌会充满整个培养皿（不算有抗生素的格子）。

说明
【样例解释】 第一轮繁殖：

2 1 0

1 1 1

0 1 0

第二轮繁殖：

2 1 1

1 1 1

1 1 1

【数据范围】

对于全部数据：1≤L≤100 ，保证最终能够充满培养皿（不算有抗生素的格子）。

Sample Input
3
2 0 0
0 1 0
0 0 0
Sample Output
2
*/
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int i, j, L, cnt, m = 0;
    cin >> L;
    int **A;
    A = new int *[L];
    for (i=0; i<L; ++i) A[i] = new int [L];
    queue<int> xlable; queue<int> ylable;
    for (i=0; i<L; ++i) {
        for (j=0; j<L; ++j) {
            cin >> A[i][j];
            if (A[i][j] == 1) {
                xlable.push(i); ylable.push(j);
            }
        }
    }
    while (!xlable.empty()) {
        cnt = xlable.size();
        for (i=0; i<cnt; ++i) {
            int x = xlable.front(), y = ylable.front();
            xlable.pop(); ylable.pop();
            if (x-1>=0 && A[x-1][y]==0) {xlable.push(x-1); ylable.push(y); A[x-1][y] = 1;}
            if (y-1>=0 && A[x][y-1]==0) {xlable.push(x); ylable.push(y-1); A[x][y-1] = 1;}
            if (y+1<L && A[x][y+1]==0) {xlable.push(x); ylable.push(y+1); A[x][y+1] = 1;}
            if (x+1<L && A[x+1][y]==0) {xlable.push(x+1); ylable.push(y); A[x+1][y] = 1;}
        }
        if (!xlable.empty()) m++;
    }
    cout << m;
    return 0;
}
