
#include <queue>
using namespace std;


class Truck
{
public:
	int weight;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<int> bridge;
	for (int i = 0; i < bridge_length; ++i) {
		bridge.push(0);
	}
	int load_weight = 0;
	int cnt = 0;
	vector<int>::iterator it = truck_weights.begin();
	while ( bridge.size() != 0 ) {
		cnt++;
		load_weight -= bridge.front();
		bridge.pop();
		
		if (it != truck_weights.end()) {
			if ((load_weight + *it) <= weight) {
				bridge.push(*it);
				load_weight += *it;
				++it;
			}
			else
			{
				bridge.push(0);
			}
		}
	}
	answer = cnt;
	return answer;
}