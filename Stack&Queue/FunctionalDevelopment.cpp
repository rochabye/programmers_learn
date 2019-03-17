#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int pop_count = 0;
	while (!progresses.empty()) {
		for (int i = 0; i < progresses.size(); ++i) {
			progresses[i] += speeds[i];
		}
		if (progresses.front() >= 100) {
            int i = 0;
            while( progresses[i] >= 100 ) {
                pop_count++;
                i++;
            }
			progresses.erase(progresses.begin(), progresses.begin() + pop_count);
			speeds.erase(speeds.begin(), speeds.begin() + pop_count);
			answer.push_back(pop_count);
			pop_count = 0;
		}
	}
	return answer;
}