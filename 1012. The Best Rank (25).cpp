1012 The Best Rank (25)（25 分）
To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algebra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.

For example, The grades of C, M, E and A - Average of 4 students are given as the following:

StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

Input

Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (<=2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.

Output

For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.

The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.

If a student is not on the grading list, simply output "N/A".

Sample Input

5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
Sample Output

1 C
1 M
1 E
1 A
3 A
N/A
作者: CHEN, Yue
单位: PAT联盟
时间限制: 400ms
内存限制: 64MB
代码长度限制: 16KB


#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool is[1000000] = {false};//标记是否有这么个人
int a[1000000];
int c[1000000];
int m[1000000];
int e[1000000];
int main (){
    //    freopen("test.txt","r",stdin);
    string ss = "0ACME";
    int be = 1000000 , end = 0;
    int nn, nm;
    cin >> nn >> nm;
    for(int i = 1; i <= nn; i++) {
        int num, t1,t2,t3;
        cin >> num >> t1 >> t2 >> t3;
        c[num] = t1; m[num] = t2; e[num] = t3;
        a[num] = (c[num] + m[num] + e[num]) / 3;
        if(num < be)    be = num;
        if(num > end)    end = num;
        is[num] = true;
    }
    
    for(int j = 1; j <= nm; j++) {
        int num;
        cin >> num;
        if(is[num] == false) {
            cout << "N/A\n";
        }
        else {//遍历出每门成绩中的名次
            int r[5] = {0};
            for(int i = be; i <= end; i++) {
                if(a[num] < a[i]) {
                    r[1]++;
                }
            }
            for(int i = be; i <= end; i++) {
                if(c[num] < c[i]) {
                    r[2]++;
                }
            }
            for(int i = be; i <= end; i++) {
                if(m[num] < m[i]) {
                    r[3]++;
                }
            }
            for(int i = be; i <= end; i++) {
                if(e[num] < e[i]) {
                    r[4]++;
                }
            }
            int minn = r[1],t = 1;
            for(int i =2 ; i <= 4; i++) {//几门成绩比较并且标记位置
                if(minn > r[i]) {
                    minn = r[i];
                    t = i;
                }
            }
            cout << minn+1 << ' ' << ss[t] << endl;
        }
    }
    return 0;
}
