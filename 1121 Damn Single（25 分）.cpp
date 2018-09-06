1121 Damn Single（25 分）
"Damn Single (单身狗)" is the Chinese nickname for someone who is being single. You are supposed to find those who are alone in a big party, so they can be taken care of.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 50,000), the total number of couples. Then N lines of the couples follow, each gives a couple of ID's which are 5-digit numbers (i.e. from 00000 to 99999). After the list of couples, there is a positive integer M (≤ 10,000) followed by M ID's of the party guests. The numbers are separated by spaces. It is guaranteed that nobody is having bigamous marriage (重婚) or dangling with more than one companion.

Output Specification:
First print in a line the total number of lonely guests. Then in the next line, print their ID’s in increasing order. The numbers must be separated by exactly 1 space, and there must be no extra space at the end of the line.

Sample Input:
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
Sample Output:
5
10000 23333 44444 55555 88888


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, k , a[100000] = {0}, vis[100000] = {0};
    vector<int> v, ans;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        a[t1] = t2;
        a[t2] = t1;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        int t;
        scanf("%d", &t);
        vis[t] = 1;
        v.push_back(t);
    }
    for(int i = 0; i < v.size(); i++) {
        if(vis[a[v[i]]] == 0) ans.push_back(v[i]);
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i< ans.size(); i++) {
        if(i != 0) printf(" ");
        printf("%05d",ans[i]);
    }
}
