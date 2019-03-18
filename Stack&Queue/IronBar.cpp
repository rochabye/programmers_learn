#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string arrangement) {
	int answer = 0;
	
	stack<char> stick;
	for (int i = 0; i < arrangement.size(); ++i) {
		if (arrangement[i] == '(') {
			stick.push(arrangement[i]);
		}
		else {
			stick.pop();
			if (arrangement[ i - 1 ] == '(' ) { // laser
				answer += stick.size();
			}
			else {
				answer += 1;
			}
		}
	}
	return answer;
}