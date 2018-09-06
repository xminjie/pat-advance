1107 Social Clusters（30 分）
When register on a social network, you are always asked to specify your hobbies in order to find some potential friends with the same hobbies. A social cluster is a set of people who have some of their hobbies in common. You are supposed to find all the clusters.

Input Specification:
Each input file contains one test case. For each test case, the first line contains a positive integer N (≤1000), the total number of people in a social network. Hence the people are numbered from 1 to N. Then N lines follow, each gives the hobby list of a person in the format:

K
where K
​i
​​  (>0) is the number of hobbies, and h
​i
​​ [j] is the index of the j-th hobby, which is an integer in [1, 1000].

Output Specification:
For each case, print in one line the total number of clusters in the network. Then in the second line, print the numbers of people in the clusters in non-increasing order. The numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
Sample Output:
3
4 3 1

有点弯弯的并查集
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int fa[1010] ,cnt[1010];
int find(int x) {
    int a = x;
    while(x != fa[x])
        x = fa[x];
    while(a != fa[a]) {
        int z = a;
        a = fa[a];
        fa[z] = x;
    }
    return x;
}
void uni(int x, int y) {
    int a = find(x);
    int b = find(y);
    fa[a] = b;
}
int main() {
    for(int i = 0; i <= 1000; i++)
        fa[i] = i;
    int n, k;
    vector<int> v;
    vector<int> a[1010];
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int t;
        scanf("%d: ", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d",&t);
            a[t].push_back(i);
        }
    }
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j < a[i].size(); j++) {
            uni(a[i][0], a[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        cnt[find(i)]++;
    }
    for(int i = 1; i <= n; i++) {
        if(i == find(i)) {
            v.push_back(cnt[i]);
        }
    }
    cout << v.size() << endl;
    sort(v.begin(),v.end(),greater<int>());
    for(int i = 0; i < v.size(); i++) {
        if(i != 0) cout << " ";
        cout << v[i];
    }
    return 0;
}
