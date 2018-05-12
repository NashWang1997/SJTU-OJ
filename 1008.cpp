/*
1008. 二哥买期货
Description
二哥想知道在一段时期内，一共有多少个交易日。期货交易日的限定如下：

周六、周日不能交易
元旦期间（1月1日）不能交易
五一劳动节期间（5月1日至3日）不能交易
十一国庆节期间（10月1日至7日）不能交易
没有在上述要求中提到的日期均可交易
Input Format
第一行有一个整数n，表示一共有n组数据。

每组数据都有一行，是两个用空格分开的日期，分别为开始日期和结束日期。日期格式为YYYY-MM-DD（比如2010-11-11）；数据保证开始日期不晚于结束日期。

对于所有数据：n≤365
对于30%的数据：日期范围从2010-11-23至2012-12-21

对于70%的数据：日期范围从1900-01-01至9999-12-31

Output Format
输出共n行，每行一个整数，对应于一组数据。

每组数据需要输出在指定日期区间内，共有多少个交易日；区间的开始和结束日期也算在内（如果是交易日的话）。

Sample Input
4
2010-11-18 2010-11-20
2010-01-01 2010-01-01
2010-05-01 2010-05-03
2010-10-01 2010-10-07
Sample Output
2
0
0
0
*/
#include <iostream>
#include <stdio.h>
using namespace std;

void ch_int(char *date, int *ymd) //change char to int
{
    int year = (date[0]-'0') * 1000 + (date[1]-'0') * 100 + (date[2]-'0') * 10 + (date[3]-'0');
    ymd[0] = year;
    int month = (date[5]-'0') * 10 + (date[6]-'0');
    ymd[1] = month;
    int day = (date[8]-'0') * 10 + (date[9]-'0');
    ymd[2] = day;
}

bool is_rn(int year)
{
    if ((year%400==0) || (year%100!=0&&year%4==0)) return true;
    else return false;
}

int get_days(int *ymd1, int *ymd2)
{
    int num_days = 0, i;
    for (i=ymd1[0]; i<=ymd2[0]; ++i) {
        if (is_rn(i)) num_days += 366;
        else num_days += 365;
    }
    int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (is_rn(ymd1[0])) days_in_month[1] = 29;
    for (i=0; i<ymd1[1]-1; ++i) num_days -= days_in_month[i];
    num_days -= (ymd1[2] - 1);
    if (!is_rn(ymd2[0])) days_in_month[1] = 28;
    for (i=ymd2[1]; i<12; ++i) num_days -= days_in_month[i];
    num_days -= (days_in_month[ymd2[1]-1] - ymd2[2]);
    return num_days;
}

int zeller(int *ymd)
{
    int m, year;
    if (ymd[1]==1 || ymd[1]==2) {
        m = ymd[1] + 12;
        year = ymd[0] - 1;
    }
    else {
        m = ymd[1];
        year = ymd[0];
    }
    int c = year / 100, y = year - c * 100;
    int w = c/4 - 2*c + y + y/4 + 13*(m+1)/5 + ymd[2] - 1;
    if (w >= 0) return w%7;
    else {
        while (w < 0) w += 7;
        return w;
    }
}

int count_weekdays(int num_days, int weekd1, int weekd2)
{
    int cnt = 0, total = num_days;
    if (weekd1 != 0) {
        cnt += (6 - weekd1);
        total -= (8 - weekd1);
    }
    else {
        total -= 1;
    }
    if (weekd2 != 0) {
        cnt += (weekd2 > 5) ? 5 : weekd2;
        total -= weekd2;
    }
    else {
        cnt += 5;
        total -= 7;
    }
    return cnt + (total * 5 / 7);
}

bool between(int *test_date, int *start_date, int *end_date)
{
    int test1[] = {test_date[0]-start_date[0], test_date[1]-start_date[1], test_date[2]-start_date[2]};
    int test2[] = {end_date[0]-test_date[0], end_date[1]-test_date[1], end_date[2]-test_date[2]};
    if (test1[0]<0 || (test1[0]==0&&test1[1]<0) || (test1[0]==0&&test1[1]==0&&test1[2]<0)) return false;
    else if (test2[0]<0 || (test2[0]==0&&test2[1]<0) || (test2[0]==0&&test2[1]==0&&test2[2]<0)) return false;
    else return true;
}

int cut_special_days(int cnt, int *ymd1, int *ymd2)
{
    int sp[11][3] = {{0,1,1}, {0,5,1}, {0,5,2}, {0,5,3}, {0,10,1}, {0,10,2}, {0,10,3}, {0,10,4}, {0,10,5}, {0,10,6}, {0,10,7}};
    int start_year = ymd1[0], end_year = ymd2[0], i, j, result = cnt;
    for (i=start_year; i<=end_year; ++i) {
        for (j=0; j<11; ++j) {
            int tmp[] = {i, sp[j][1], sp[j][2]};
            if (between(tmp, ymd1, ymd2) && zeller(tmp)!=6 && zeller(tmp)!=0) {
                result--;
            }
        }
    }
    return result;
}

int main()
{
    int n, i;
    char date1[11], date2[11];
    int ymd1[3], ymd2[3];
    scanf("%d", &n);
    for (i=0; i<n; ++i) {
        scanf("%s%s", &date1, &date2);
        ch_int(date1, ymd1); ch_int(date2, ymd2);
        int num_days = get_days(ymd1, ymd2); //how many days between two dates
        int weekd1 = zeller(ymd1), weekd2 = zeller(ymd2); //which day it is
        int cnt = count_weekdays(num_days, weekd1, weekd2); // how many weekdays
        int result = cut_special_days(cnt, ymd1, ymd2);
        printf("%d\n", result);
    }
    return 0;
}
