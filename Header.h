#pragma once
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>







using std::cout;
template <class T>
class Stack final {
private:
	class stack_node {
	public:
		T data;
		stack_node* next;
		stack_node() :data{ 0 }, next{ nullptr }
		{

		}
		stack_node(const T& data1) :data{ data1 }, next{ nullptr }
		{

		}
	};
	size_t size1 = 0;
	stack_node* head;
	stack_node* ptr;
public:
	//constructors of the stack
	Stack() {
		head = nullptr;
		ptr = nullptr;
		size1 = 0;
	}
	Stack(const Stack& a) {//copy constructor
		if (this != &a) {

			stack_node* ptr1 = a.head;
			for (size_t i = 0; i < a.size1; i++) {
				push(ptr1->data);
				ptr1 = ptr1->next;
			}
			size1 = a.size1;
		}
		else {
			head = nullptr;
			size1 = 0;
			ptr = nullptr;
		}
	}
	//funcs of my_stack
	void push(const T& data1) {
		if (size1 == 0) {
			size1++;
			head = new (std::nothrow)stack_node(data1);
			if (head == nullptr)exit(1);
			ptr = head;
		}
		else {
			size1++;
			ptr->next = new (std::nothrow)stack_node(data1);
			if (ptr->next == nullptr)exit(1);
			ptr = ptr->next;
		}
		return;
	}
	T& top() {
		if (head != nullptr) {
			return ptr->data;
		}
		abort();
	}
	void pop() {
		if (size1 > 1) {
			delete ptr;
			size1--;
			ptr = head;
			for (int i = 0; i < size1 - 1; i++) {
				ptr = ptr->next;
			}
			return;
		}
		else if (size1 == 1) {
			size1 = 0;
			ptr = nullptr;
			delete head;
			head = nullptr;
		}
		return;
	}
	bool empty() {
		if (head == nullptr)return true;
		return false;
	}
	size_t size() {
		return size1;
	}
	void emplace(const T& data1) {
		push(data1);
		return;
	}
	//overloaded operators
	bool operator==(const Stack& a) {
		stack_node* ptr1 = head;
		stack_node* ptr2 = a.head;
		if (size1 == a.size1) {
			for (size_t i = 0; i < size1; i++) {
				if (ptr1->data != ptr2->data)return 0;
			}
			return 1;
		}
		return 0;

	}
	void operator=(const Stack& a) {
		if (this != &a) {
			if (this->head != nullptr) {
				this->~Stack();
				stack_node* ptr1 = a.head;
				for (size_t i = 0; i < a.size1; i++) {
					push(ptr1->data);
					ptr1 = ptr1->next;
				}
				size1 = a.size1;
			}
			else {
				stack_node* ptr1 = a.head;
				for (size_t i = 0; i < a.size1; i++) {
					push(ptr1->data);
					ptr1 = ptr1->next;
				}
				size1 = a.size1;
			}
		}
		return;

	}

	//destructor
	~Stack() {
		stack_node* ptr1 = head;
		stack_node* ptr2 = head;
		for (size_t i = 0; i < size1; i++) {
			ptr2 = ptr2->next;
			delete ptr1;
			ptr1 = ptr2;


		}
		size1 = 0;
		head = nullptr;
		ptr = nullptr;
		return;
	}



};

