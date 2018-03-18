/*
1005. 数独
题目描述
数独游戏，具体规则如下：

每一行都用到1,2,3,4,5,6,7,8,9, 位置不限，

每一列都用到1,2,3,4,5,6,7,8,9, 位置不限，

每3*3的格子（共9个这样的格子）都用到1,2,3,4,5,6,7,8,9, 位置不限，

游戏过程就是用1,2,3,4,5,6,7,8,9填充空白，并满足每行，每列，每个九宫格都用到1,2,3,4,5,6,7,8,9，

如下是个正确的sudoku:

数独

输入格式
输入n个数独，你来验证它是否违反规则。

第一行为数独个数，第二行开始为第一个数独，之后第二个，至第n个。

注意：每个数独间有个回车隔开。

输出格式
若正确则输出"Right",否则输出"Wrong", 输出一个换一行。

说明
1<=n<=20(输入的数独个数）

不论输入的数独是否正确，数据保证每个数都在1-9间。

Sample Input
2
5 8 1 4 9 3 7 6 2
9 6 3 7 1 2 5 8 4
2 7 4 8 6 5 9 3 1
1 2 9 5 4 6 3 7 8
4 3 6 1 8 7 2 9 5
7 5 8 3 2 9 1 4 6
8 9 2 6 7 1 4 5 3
6 1 5 9 3 4 8 2 7
3 4 7 2 5 8 6 1 9

1 2 3 4 5 6 7 8 9
2 3 4 5 6 7 8 9 1
3 4 5 6 7 8 9 1 2
4 5 6 7 8 9 1 2 3
5 6 7 8 9 1 2 3 4
6 7 8 9 1 2 3 4 5
7 8 9 1 2 3 4 5 6
8 9 1 2 3 4 5 6 7
9 1 2 3 4 5 6 7 8
Sample Output
Right
Wrong
*/
#include <iostream>
#include <queue>
using namespace std;

int sudoku[9][9];

bool checkrow()
{
    int i, j, k;
    for (i=0; i<9; ++i) {
        for (j=0; j<9; ++j) {
            for (k=0; k<9; ++k) {
                if (sudoku[i][k] == j+1) break;
            }
            if (k == 9) return false;
        }
    }
    return true;
}

bool checkline()
{
    int i, j, k;
    for (i=0; i<9; ++i) {
        for (j=0; j<9; ++j) {
            for (k=0; k<9; ++k) {
                if (sudoku[k][i] == j+1) break;
            }
            if (k == 9) return false;
        }
    }
    return true;
}

bool checksquare()
{
    int index[] = {1, 4, 7};
    int mv[] = {-1, 0, 1};
    int i, j, k, m, n;
    bool flag = false;
    for (i=0; i<3; ++i) {
        for (j=0; j<3; ++j) {
            for (k=0; k<9; ++k) {
                for (m=0; m<3; ++m) {
                    for (n=0; n<3; ++n) {
                        if (sudoku[index[i]+mv[m]][index[j]+mv[n]] == k+1) flag = true;
                    }
                }
                if (!flag) return false;
                flag = false;
            }
        }
    }
    return true;
}

int main()
{
    int i, j, k, n;
    cin >> n;
    for (i=0; i<n; ++i) {
        for (j=0; j<9; ++j) {
            for (k=0; k<9; ++k) {
                cin >> sudoku[j][k];
            }
        }
        bool row = false, line = false, square = false;
        row = checkrow();
        line = checkline();
        square = checksquare();
        if (row && line && square) cout << "Right\n";
        else cout << "Wrong\n";
    }
    return 0;
}
