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
#include <cstdlib>
using namespace std;
 
int fillin(int **area, int **result, int row, int line, int a, int b)
{
	int i, j, cnt = 0;
	if (row != 0) {
		cnt = result[row-1][line];
		for (j=0; j<b; ++j) {
			cnt -= area[row-1][line+j];
			cnt += area[row+a-1][line+j];
		}
	}
	else if (line != 0) {
		cnt = result[row][line-1];
		for (i=0; i<a; ++i) {
			cnt -= area[row+i][line-1];
			cnt += area[row+i][line+b-1];
		}
	}
	else {
		for (i=0; i<a; ++i) {
			for (j=0; j<b; ++j) {
				cnt += area[row+i][line+j];
			}
		}
	}
	return cnt;
}
 
int main()
{
	int L, W, i, j;
	scanf("%d%d", &L, &W);
	int **area;
	area = new int *[L];
	for (i=0; i<L; ++i) area[i] = new int [W];
	for (i=0; i<L; ++i) {
		for (j=0; j<W; ++j) {
			scanf("%d", &area[i][j]);
		}
	}
	int a, b;
	scanf("%d%d", &a, &b);
	int **result;
	result = new int *[L-a+1];
	for (i=0; i<L-a+1; ++i) {
		result[i] = new int [W-b+1];
	}
	for (i=0; i<L-a+1; ++i) {
		for (j=0; j<W-b+1; ++j) {
			result[i][j] = fillin(area, result, i, j, a, b);
			//printf("%d\t%d\t%d\n", i, j, result[i][j]);
		}
	}
	int max = result[0][0];
	for (i=0; i<L-a+1; ++i) {
		for (j=0; j<W-b+1; ++j) {
			if (result[i][j] > max) max = result[i][j];
		}
	}
	printf("%d\n", max);
	return 0;
}
