#include <string>
#include <vector>

using namespace std;
vector<int> solution(vector<int> prices) {
	vector<int> answer;
	answer.resize(prices.size());
	for (int i = 0; i < answer.size(); ++i) {
		answer[i] = answer.size() - 1 - i;
	}

	for (int i = 0; i < prices.size() - 1; ++i) {
		for (int j = i + 1; j < prices.size(); ++j) {
			if (prices[i] > prices[j]) {
				answer[i] = j - i;
				break;
			}
		}
	}
	return answer;
}
