#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	priority_queue< int, vector< int >, less<int> > temp;
	int answer = 0;
	int cnt_date = 0;
	for (int i = 0; i < k; ++i) {
		if (i == dates[cnt_date] ) {
			temp.push(supplies[cnt_date]);
			if (cnt_date != supplies.size() - 1) {
				++cnt_date;
			}
		}
		if (stock == 0) {
			stock += temp.top();
			temp.pop();
			answer++;
		}
		--stock;
	}

	return answer;
}