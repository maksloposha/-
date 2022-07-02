#pragma once
#include<iostream>
using namespace std;

template <class T>
class Queue
{private:
	T data[100];
	int head, tail;
public:
	Queue() {
		head = 0;
		tail = 0;
	}
	Queue(int length, T* array) {
		for (int i = 0; i < length; i++) {
			data[i] = array[i];
			tail++;
		}
	}
	int getTail(){ return tail; }
	T* getData(){ return data; }
	void push(T el) {
		if (tail == 99) {
			cout << "Qieue is full";
			return;
		}
		else {
			data[tail++] = el;
		}
	}
	T pop() {
		if (tail == head) {
			cout << "Queue is empty ";
			return;
		}

		T resElement = data[0];
		tail--;
		for (int i = 0; i <= tail; i++) {
			data[i] = data[i + 1];
		}
		data[tail + 1] = NULL;

		return resElement;
	}
	friend ostream& operator<<(ostream& out, Queue<T>& anQueue)
	{
		T* tmp = anQueue.getData();
		for (int i = 0; i <= anQueue.getTail(); i++) {
			out << tmp[i]<< " ";
		}
		return out;
	}
};


