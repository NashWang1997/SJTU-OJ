/*
1001. ����ժƻ��
��Ŀ����
����ƽ��ϲ���Լ���һЩ���������Դ�Ϊд����Ϳ���Ӱ֮�����󰮺á�����������ֵ�һ��ƻ�������˲�ժ��ʱ�򣬵������ڶ������ߵ����ƣ���Щƻ��̫��ժ���������Ƕ��������һ�����ӣ������������ժ�������ƻ����

������һ�������ж����ˣ�������ժƻ��֮ǰ֪���Լ���ժ������ƻ�������ʵ��̫�٣�ƻ������ïʢ����Ҫ����������ԭ�򣩣��������������µ�ƻ���Լ��������ҵ�ͷ�ϡ�

�����ʽ
���빲�����С�

��1����3���������ֱ��ʾ��������ߡ����ӵĸ߶Ⱥ�ƻ���ĸ���n��

��2����n���������ֱ��ʾÿ��ƻ���ĸ߶ȡ�

�����ʽ
���һ������m����ʾ���������ժ����ƻ���ĸ���Ϊm��

˵��
����ȫ�����ݣ��߶�Ϊ1000���µ���������ƻ���ĸ���1��n��1000��

Sample Input
177 40 10
180 151 152 193 168 255 278 303 211 217
Sample Output
7
*/
#include <iostream>
using namespace std;

int main()
{
    int h1, h2, n, i, m = 0, top, app;
    cin >> h1 >> h2 >> n;
    top = h1 + h2;
    for (i=0; i<n; ++i) {
        cin >> app;
        if (app <= top) m++;
    }
    cout << m;
    return 0;
}