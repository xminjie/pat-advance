1001 A+B Format (20)（20 分）
Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input

Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input

-1000000 9
Sample Output

-999,991

#include <iostream>
using namespace std;
int main() {
	stack <int> s; 
	int a, b, sum, count = 0, j = 0,jj = 0;
	int ar[10],br[10];
	cin >> a >> b;
	sum = a + b;
	if(sum < 0 ) {
		cout << '-' ;
		sum = sum * -1;
	} 
	if(sum == 0) {
		cout << 0;
	return 0;
}

