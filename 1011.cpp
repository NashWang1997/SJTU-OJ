/*
1011. 复数类
题目描述
写一个复数类，实现以下程序主函数中所需要的功能。

#include <iostream>
using namespace std;

class MyComplex
{
private:
  double x,y;
public:
  /* Implementation of MyComplex */
  /*
};

int main()
{
  MyComplex z1;
  MyComplex z2;

  cin >> z1 >> z2;

  cout << z1 + z2 <<endl;
  cout << z1 - z2 <<endl;
  cout << z1 * z2 <<endl;
  cout << z1 / z2 <<endl;
  cout << (z1 += z2) <<endl;
  cout << (z1 -= z2) <<endl;
  cout << (z1 *= z2) <<endl;
  cout << (z1 /= z2) <<endl;

  return 0;
}
输入格式
输入包括两行，第一行是两个整数a, b（0<|a|+1,|b|<10001），表示复数a+bi。

第二行是两个整数c, d（0<|c|+1,|d|<10001），表示复数c+di。输入数据保证不出现除以0的情况。

输出格式
输出包括八行，对应所给程序中的输出。注意输出浮点数保留2位小数。

Sample Input 1
3 6
-3 5
Sample Output 1
0.00 11.00
6.00 1.00
-39.00 -3.00
0.62 -0.97
0.00 11.00
3.00 6.00
-39.00 -3.00
3.00 6.00
Sample Input 2
5 9
5 -9
Sample Output 2
10.00 0.00
0.00 18.00
106.00 0.00
-0.53 0.85
10.00 0.00
5.00 9.00
106.00 0.00
5.00 9.00
*/
#include <iostream>
#include <iomanip>
using namespace std;

class MyComplex {
    friend ostream & operator<<(ostream &out, const MyComplex &obj);
    friend istream & operator >> (istream &in, MyComplex &obj);
    friend MyComplex operator+(const MyComplex &z1, const MyComplex &z2);
    friend MyComplex operator-(const MyComplex &z1, const MyComplex &z2);
    friend MyComplex operator*(const MyComplex &z1, const MyComplex &z2);
    friend MyComplex operator/(const MyComplex &z1, const MyComplex &z2);
    friend MyComplex operator+=(MyComplex &z1, const MyComplex &z2);
    friend MyComplex operator-=(MyComplex &z1, const MyComplex &z2);
    friend MyComplex operator*=(MyComplex &z1, const MyComplex &z2);
    friend MyComplex operator/=(MyComplex &z1, const MyComplex &z2);
private:
    double x;
    double y;
};
ostream & operator<< (ostream &out, const MyComplex& obj)
{
    out << fixed << setprecision(2) << obj.x << " " << obj.y;
    return out;
}
istream & operator >> (istream &in, MyComplex &obj)
{
    in >> obj.x >> obj.y;
    return in;
}
MyComplex operator+(const MyComplex &z1, const MyComplex &z2)
{
    MyComplex tmp;
    tmp.x = z1.x + z2.x;
    tmp.y = z1.y + z2.y;
    return tmp;
}
MyComplex operator-(const MyComplex &z1, const MyComplex &z2)
{
    MyComplex tmp;
    tmp.x = z1.x - z2.x;
    tmp.y = z1.y - z2.y;
    return tmp;
}
MyComplex operator*(const MyComplex &z1, const MyComplex &z2)
{
    MyComplex tmp;
    tmp.x = z1.x * z2.x - z1.y * z2.y;
    tmp.y = z1.x * z2.y + z1.y * z2.x;
    return tmp;
}
MyComplex operator/(const MyComplex &z1, const MyComplex &z2)
{
    MyComplex tmp;
    tmp.x = (z1.x * z2.x + z1.y * z2.y) / (z2.x * z2.x + z2.y * z2.y);
    tmp.y = (-z1.x * z2.y + z1.y * z2.x) / (z2.x * z2.x + z2.y * z2.y);
    return tmp;
}
MyComplex operator+=(MyComplex &z1, const MyComplex &z2)
{
    z1.x += z2.x;
    z1.y += z2.y;
    return z1;
}
MyComplex operator-=(MyComplex &z1, const MyComplex &z2)
{
    z1.x -= z2.x;
    z1.y -= z2.y;
    return z1;
}
MyComplex operator*=(MyComplex &z1, const MyComplex &z2)
{
    double tmpx = z1.x;
    z1.x = z1.x * z2.x - z1.y * z2.y;
    z1.y = tmpx * z2.y + z1.y * z2.x;
    return z1;
}
MyComplex operator/=(MyComplex &z1, const MyComplex &z2)
{
    double tmpx = z1.x;
    z1.x = (z1.x * z2.x + z1.y * z2.y) / (z2.x * z2.x + z2.y * z2.y);
    z1.y = (-tmpx * z2.y + z1.y * z2.x) / (z2.x * z2.x + z2.y * z2.y);
    return z1;
}
int main()
{
    MyComplex z1;
    MyComplex z2;
    cin >> z1 >> z2;
    cout << z1 + z2 <<endl;
    cout << z1 - z2 <<endl;
    cout << z1 * z2 <<endl;
    cout << z1 / z2 <<endl;
    cout << (z1 += z2) <<endl;
    cout << (z1 -= z2) <<endl;
    cout << (z1 *= z2) <<endl;
    cout << (z1 /= z2) <<endl;
  return 0;
}
