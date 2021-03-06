/*
1010. 二哥的储蓄计划
Description
二哥的零花钱一直都是自己管理。每个月的月初妈妈给二哥300元钱，二哥会预算这个月的花销，并且总能做到实际花销和预算的相同。

为了让二哥学习如何储蓄，妈妈提出，二哥可以随时把整百的钱存在她那里，到了年末她会加上20%还给二哥。因此二哥制定了一个储蓄计划：每个月的月初，在得到妈妈给的零花钱后，如果她预计到这个月的月末手中还会有多于100元或恰好100元，她就会把整百的钱存在妈妈那里，剩余的钱留在自己手中。

例如11月初二哥手中还有83元，妈妈给了二哥300元。二哥预计11月的花销是180元，那么她就会在妈妈那里存200元，自己留下183元。到了11月月末，二哥手中会剩下3元钱。

二哥发现这个储蓄计划的主要风险是，存在妈妈那里的钱在年末之前不能取出。有可能在某个月的月初，二哥手中的钱加上这个月妈妈给的钱，不够这个月的原定预算。如果出现这种情况，二哥将不得不在这个月省吃俭用，压缩预算。

现在请你根据2009年1月到12月每个月二哥的预算，判断会不会出现这种情况。如果不会，计算到2009年年末，妈妈将二哥平常存的钱加上20%还给二哥之后，二哥手中会有多少钱。

Input Format
输入包括12行数据，每行包含一个小于350的非负整数，分别表示1月到12月二哥的预算。

Output Format
输出包括一行，这一行只包含一个整数。如果储蓄计划实施过程中出现某个月钱不够用的情况，输出-X，X表示出现这种情况的第一个月；否则输出到2009年年末二哥手中会有多少钱。

Sample Input
290
230
280
200
300
170
340
50
90
80
200
60
Sample Output
-7
Sample Input
290
230
280
200
300
170
330
50
90
80
200
60
Sample Output
1580
*/
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int i;
    int budget[12], start = 0, rest, bank = 0;
    for (i=0; i<12; ++i) {
        start += 300;
        scanf("%d", &budget[i]);
        if (start < budget[i]) {
            printf("%d\n", -1*(i+1));
            return 0;
        }
        else {
            rest = (start - budget[i]) / 100;
            if (rest > 0) {
                bank += (rest * 100);
                start -= (rest * 100);
            }
            start -= budget[i];
        }
    }
    double money = start + bank * 1.2;
    printf("%.0f\n", money);
    return 0;
}
