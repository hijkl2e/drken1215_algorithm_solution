#include <bits/stdc++.h>

using namespace std;

template <typename T>
class LinkedList {
public:
	LinkedList() : head(new Node()), tail(new Node()), sz{} {
		head->next = tail;
		tail->prev = head;
	}
	~LinkedList() {
		Node *node = head;
		while (node) {
			Node *next = node->next;
			delete node;
			node = next;
		}
	}
	T &front() {
		return head->next->value;
	}
	T &back() {
		return tail->prev->value;
	}
	bool empty() {
		return !sz;
	}
	size_t size() {
		return sz;
	}
	void push_front(const T &value) {
		Node *node = new Node(value);
		node->prev = head;
		node->next = head->next;
		head->next->prev = node;
		head->next = node;
		++sz;
	}
	void pop_front() {
		Node *node = head->next;
		head->next = node->next;
		node->next->prev = head;
		delete node;
		--sz;
	}
	void push_back(const T &value) {
		Node *node = new Node(value);
		node->next = tail;
		node->prev = tail->prev;
		tail->prev->next = node;
		tail->prev = node;
		++sz;
	}
	void pop_back() {
		Node *node = tail->prev;
		tail->prev = node->prev;
		node->prev->next = tail;
		delete node;
		--sz;
	}
private:
	struct Node {
		Node(const T &val = T{}) : prev(nullptr), next(nullptr), value(val) { }
		Node *prev, *next;
		T value;
	};
	Node *head, *tail;
	size_t sz;
};

template <typename T>
class Stack {
public:
	Stack() = default;
	T &top() {
		return lst.back();
	}
	bool empty() {
		return lst.empty();
	}
	size_t size() {
		return lst.size();
	}
	void push(T &value) {
		lst.push_back(value);
	}
	void pop() {
		lst.pop_back();
	}
private:
	LinkedList<T> lst;
};

template <typename T>
class Queue {
public:
	Queue() = default;
	T &front() {
		return lst.front();
	}
	T &back() {
		return lst.back();
	}
	bool empty() {
		return lst.empty();
	}
	size_t size() {
		return lst.size();
	}
	void push(T &value) {
		lst.push_back(value);
	}
	void pop() {
		lst.pop_front();
	}
private:
	LinkedList<T> lst;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	Stack<int> st;
	Queue<int> q;
	for (int i = 1; i < 9; ++i) {
		if (i % 2) {
			st.push(i);
		} else {
			q.push(i);
		}
	}
	while (st.size()) {
		cout << st.top() << "\n";
		st.pop();
	}
	while (q.size()) {
		cout << q.front() << "\n";
		q.pop();
	}
	return 0;
}
