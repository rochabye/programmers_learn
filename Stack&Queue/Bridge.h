#pragma once

#include <vector>

class Bridge
{
	class Node
	{
	public:
		Node(int data_) {
			data = data_;
		}
		Node *next;
		Node* prev;
		int GetData() {
			return data;
		}
	private:
		int data;
		
	};
private:
	Node* front;
	Node* rear;
public:
	Bridge( int length_, int max_load_weight_);
	virtual ~Bridge();

	void Enter( int truck );
	void Leave();
	int Front();
	bool IsEmpty();
	bool IsFull();
	bool IsOccupied( int weight );

private:
	int max_length;
	int length;
	int max_load_weight;
	int load_weight;
};

