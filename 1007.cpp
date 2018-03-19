/*
1007. 二哥领工资
题目描述
二哥当了多年的助教，今天终于要发工资了！二哥正在高兴之际，得知工资是分两部分发放的。第一部分是这学期的工资，另一部分是之前所有学期的工资总和。而领取工资时，出纳员会问二哥，两部分工资加在一起是多少，如果二哥回答错了，就只能领到这个学期的工资之前所有学期的劳动就白费了。

二哥从小道消息得知，出纳员是个对数字敏感的人，不能有一点差错，所以二哥需要一个程序来帮他算出精确的工资总和。

输入格式
输入共两行，每行是一个十进制表示的工资金额（没有正负号，小数点后有两位数字）。

输出格式
输出共一行，即精确的工资总和（没有正负号，小数点后有两位数字）。

说明
工资金额的有效数字位数不超过200位，并保证有小数点。

Sample Input
123.45
543.21
Sample Output
666.66
*/
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int p, i;
    stack <int> in1; stack <int> in2; stack <int> in3;
    stack <int> fl1; stack <int> fl2; stack <int> fl3;
    for (i=0; i<s1.length(); ++i) {
        if (s1[i] == '.') {p = i; break;}
    }
    for (i=0; i<p; i++) {
        in1.push(s1[i]-'0');
    }
    for (i=p+1; i<s1.length(); i++) {
        fl1.push(s1[i]-'0');
    }
    for (i=0; i<s2.length(); ++i) {
        if (s2[i] == '.') {p = i; break;}
    }
    for (i=0; i<p; i++) {
        in2.push(s2[i]-'0');
    }
    for (i=p+1; i<s2.length(); i++) {
        fl2.push(s2[i]-'0');
    }
    int fsize1 = fl1.size(), fsize2 = fl2.size();
    if (fsize1 > fsize2) {
        for (i=0; i<fsize2-fsize1; ++i) fl2.push(0);
    }
    else {
        for (i=0; i<fsize1-fsize2; ++i) fl1.push(0);
    }
    int tmp, r = 0, d1, d2;
    bool flag = false;
    fsize1 = fl1.size();
    for (i=0; i<fsize1; ++i) {
        d1 = fl1.top(); fl1.pop();
        d2 = fl2.top(); fl2.pop();
        tmp = (d1 + d2 + r) % 10;
        r = (d1 + d2 + r) / 10;
        if (tmp != 0) flag = true;
        if (flag) fl3.push(tmp);
    }
    int M = (in1.size() > in2.size()) ? in1.size() : in2.size();
    for (i=0; i<M; ++i) {
        d1 = in1.top(); in1.pop();
        d2 = in2.top(); in2.pop();
        tmp = (d1 + d2 + r) % 10;
        r = (d1 + d2 + r) / 10;
        in3.push(tmp);
    }
    int isize1 = in1.size(), isize2 = in2.size();
    if (isize1 > isize2) {
        for (i=M; i<isize1; ++i) {
            d1 = in1.top(); in1.pop();
            tmp = (d1 + r) % 10;
            r = (d1 + r) / 10;
            in3.push(tmp);
        }
        in3.push(r);
    }
    else {
        for (i=M; i<isize2; ++i) {
            d2 = in2.top(); in2.pop();
            tmp = (d2 + r) % 10;
            r = (d2 + r) / 10;
            in3.push(tmp);
        }
        if (r != 0) in3.push(r);
    }
    while (!in3.empty()) {
        tmp = in3.top();
        in3.pop();
        cout << tmp;
    }
    cout << ".";
    while (!fl3.empty()) {
        tmp = fl3.top();
        fl3.pop();
        cout << tmp;
    }
    cout << endl;
    return 0;
}
