/*
1002. �����ֻ���
Description
�������Լ��ĺ�԰������һЩ������Ҳ�쵽���ջ��ʱ���ˡ���Ƭ��������һ������ΪL�����ΪW�ľ��Σ�ÿ����λ����ϻ����������Ƕ����ġ�����֪��������ĳ��ָ���������С������ô��ľ��������ڣ������Ĳ��������Ƕ��١�

Input Format
��1����2������������L�Ϳ��W��

��2������L+1�У�ÿ����W���������ֱ��ʾ��Ӧ�ĵ�λ����ϵĻ�������A�� 0��A<10 ����

��L+2����2���������ֱ���ָ���������С�ĳ���a�Ϳ��b��

Output Format
���һ������m����ʾ��ָ����С�������ڣ�����������Ϊm��

Sample Input
4 5
1 2 3 4 5
6 7 8 0 0
0 9 2 2 3
3 0 0 0 1
3 3
Sample Output
38
��������
���Ͻǣ�38 = (1+2+3) + (6+7+8) + (0+9+2)

���ݷ�Χ
����30%�����ݣ� 1��L,W��100��

����100%�����ݣ� 1��L,W��1000��

ȫ�������С���㣺1��a��L��1��b��W ��
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
