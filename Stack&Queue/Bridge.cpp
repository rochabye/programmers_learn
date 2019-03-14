#include "pch.h"
#include "Queue.h"
#include <iostream>

using namespace std;

Bridge::Bridge( int max_length_, int max_load_weight_)
	: length( 0 )
	, load_weight( 0 )
	, max_length( max_length_ )
	, max_load_weight( max_load_weight_ )
	, front( NULL )
	, rear( NULL )
{
}

void Bridge::Enter( int truck )
{
	if ( !IsOccupied( truck ) || IsFull() ) {
		return;
	}
	Node* node = new Node(truck);
	if ( IsEmpty() ) {
		front = node;
		rear = node;
	}
	else
	{
		Node* temp = rear;
		rear = node;
		rear->next = temp;
		temp->prev = rear;
	}
	load_weight += truck;
	length++;
}

void Bridge::Leave() {
	Node* temp = front;
	front = temp->prev;
	
	length--;
	load_weight -= temp->GetData();
	delete temp;
}
bool Bridge::IsEmpty() {
	return (length == 0) ? true : false;
}
bool Bridge::IsFull() {
	return (length == max_length) ? true : false;
}

bool Bridge::IsOccupied( int truck )
{
	return ( max_load_weight >= ( load_weight + truck ) ) ? true : false;
}
int Bridge::Front() {
	//
}
Bridge::~Bridge()
{
}
