#include <string>
#include <vector>

using namespace std;


void PushHeap(vector< int >& heap, int new_value) {
	heap.push_back(new_value);
	int index = heap.size() - 1;

	while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
		swap(heap[index], heap[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}

void PopHeap(vector< int >& heap) {
	heap[0] = heap.back();
	heap.pop_back();
	int here = 0;

	while (true) {
		int left = here * 2 + 1, right = here * 2 + 2;
		if (left >= heap.size()) break;
		int next = here;
		if (heap[next] < heap[left]) next = left;
		if (right < heap.size() && heap[next] < heap[right]) next = right;
		if (next == here) break;
		swap(heap[here], heap[next]);
		here = next;
	}
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    return answer;
}