#include <string>
#include <vector>

#include <algorithm>
using namespace std;

void PushMinHeap(vector< int >& heap, int new_value) {
	heap.push_back(new_value);
	int index = heap.size() - 1;

	while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
		swap(heap[index], heap[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}
int PopMinHeap(vector< int >& heap) {
	int pop_result = heap[0];
	heap[0] = heap.back();
	heap.pop_back();
	int here = 0;

	while (true) {
		int left = here * 2 + 1, right = here * 2 + 2;
		if (left >= heap.size())
			break;
		int next = here;
		if ( heap[ left ] < heap[next] ) next = left;
		if ( right < heap.size() && heap[right] < heap[next]) next = right;
		if (next == here) break;
		swap(heap[here], heap[next]);
		here = next;
	}
	return pop_result;
}
/////////////////////////////////////////////////

void PushMaxHeap(vector< int >& heap, int new_value) {
	heap.push_back(new_value);
	int index = heap.size() - 1;

	while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
		swap(heap[index], heap[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}
int PopMaxHeap(vector< int >& heap) {
	int pop_result = heap[0];
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
	return pop_result;
}


vector< int > solution(vector<string> operations) {
	vector< int > result;
	vector< int > max_heap;
	vector< int > min_heap;
	for (int i = 0; i < operations.size(); ++i) {
		string operation = operations[i];
		if (operation.compare(0, 1, "I") == 0) {
			int value = atoi(operation.assign(operation.begin() + 2, operation.end()).c_str());
			PushMaxHeap(max_heap, value);
			PushMinHeap(min_heap, value);
		}
		else if (operation.compare(0, 1, "D") == 0) {
			if (max_heap.empty()) {
				break;
			}
			int value = atoi(operation.assign(operation.begin() + 2, operation.end()).c_str());
			if (value == 1) {
				int val = PopMaxHeap(max_heap);
				vector<int>::iterator it;
				it = find(min_heap.begin(), min_heap.end(), val );
				if (!min_heap.empty() && it != min_heap.end()) {
					min_heap.erase(it);
				}
			}
			else if (value == -1) {
				int val = PopMinHeap(min_heap);
				vector<int>::iterator it;
				it = find(max_heap.begin(), max_heap.end(), val);
				if ( !max_heap.empty() && it != max_heap.end() ) {
					max_heap.erase(it);
				}
			}
		}
	}
	if (max_heap.empty()) {
		result.push_back(0);
	}
	else {
		result.push_back(PopMaxHeap(max_heap));
	}
	if (min_heap.empty()) {
		result.push_back(0);
	}
	else {
		result.push_back(PopMinHeap(min_heap));
	}
	return result;
}