#include <string>
#include <vector>

using namespace std;
vector<int> solution(vector<int> heights) {
	vector<int> answer;
	answer.resize(heights.size());
	int cnt = heights.size() - 1;
	for (int i = heights.size() - 1; i >= 0; --i) {
		int shoot_top = heights[i];
		for (int j = i ; j >= 0; --j) {
			if (shoot_top < heights[j]) {
				answer[i] = j + 1;
				break;
			}
		}
	}
	return answer;
}