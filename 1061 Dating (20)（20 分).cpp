1061 Dating (20)（20 分）
Sherlock Holmes received a note with some strange strings: "Let's date! 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm". It took him only a minute to figure out that those strange strings are actually referring to the coded time "Thursday 14:04" -- since the first common capital English letter (case sensitive) shared by the first two strings is the 4th capital letter 'D', representing the 4th day in a week; the second common character is the 5th capital letter 'E', representing the 14th hour (hence the hours from 0 to 23 in a day are represented by the numbers from 0 to 9 and the capital letters from A to N, respectively); and the English letter shared by the last two strings is 's' at the 4th position, representing the 4th minute. Now given two pairs of strings, you are supposed to help Sherlock decode the dating time.

Input Specification:

Each input file contains one test case. Each case gives 4 non-empty strings of no more than 60 characters without white space in 4 lines.

Output Specification:

For each test case, print the decoded time in one line, in the format "DAY HH:MM", where "DAY" is a 3-character abbreviation for the days in a week -- that is, "MON" for Monday, "TUE" for Tuesday, "WED" for Wednesday, "THU" for Thursday, "FRI" for Friday, "SAT" for Saturday, and "SUN" for Sunday. It is guaranteed that the result is unique for each case.

Sample Input:

3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
Sample Output:

THU 14:04
#
福尔摩斯的约会
#

#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	string da[] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	int i;
	for(i = 0; i < s1.size(); i++) {
		if(s1[i] == s2[i] && (s1[i] >= 'A' && s1[i] <= 'G')) {
			cout << da[s1[i]-'A'] << ' ';
			i++;
			break;
		}
	}
	for(; i < s1.size() ; i++) {
		if(s1[i] == s2[i] && (s1[i] >= 'A' && s1[i] <= 'N')) {
			cout << s1[i]-'A'+10 << ":";
			break;
		}
		if(s1[i] == s2[i] && isdigit(s1[i])) {
			printf("%02d:",s1[i]-'0');
			break;
		}
	}
	for(i = 0; i < s3.size(); i++) {
		if(s3[i] == s4[i] && isalpha(s3[i])){
			printf("%02d",i);
	 		break;
	 	}
	}
	return 0;
}