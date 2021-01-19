// Copyright 2021 Uskova
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

#include <iostream>

template <class T>
class MyStack {
 private:
    size_t size;
    int top_index;
    T* stack;
 public:
    explicit MyStack(size_t);
    explicit MyStack(const MyStack&);
    ~MyStack();
    T get() const;
    T pop();
    int push(T);
    bool isFull() const;
    bool isEmpty() const;
};

template <class T>
MyStack<T>::MyStack(size_t _size) :
    size(_size), top_index(-1) {
    stack = new T[size];
}

template <class T>
MyStack<T>::MyStack(const MyStack& newStack) {
    this->stack = new T[newStack.size];
    this->size = newStack.size;
    this->top_index = newStack.top_index;
    for (int i = 0; i <= top_index; i++) {
        this->stack[i] = newStack.stack[i];
    }
}

template <class T>
MyStack<T>::~MyStack() {
    delete[] stack;
}

template <class T>
T MyStack<T>::get() const {
    if (!this->isEmpty()) {
        return this->stack[top_index];
    } else {
        return -1;  // "Empty stack!"
    }
}

template <class T>
T MyStack<T>::pop() {
    if (!this->isEmpty()) {
        T res = this->stack[top_index];
        this->stack[top_index] = 0;
        this->top_index -= 1;
        return res;
    } else {
        return -1;  // "Empty stack!"
    }
}

template <class T>
int MyStack<T>::push(T val) {
    if (!this->isFull()) {
        this->top_index += 1;
        this->stack[top_index] = val;
        return 0;
    } else {
        return -1;  // "Full stack!";
    }
}

template <class T>
bool MyStack<T>::isFull() const {
    if (this->top_index == (size - 1))
        return true;
    else
        return false;
}

template <class T>
bool MyStack<T>::isEmpty() const {
    if (this->top_index == -1)
        return true;
    else
        return false;
}

#endif  // INCLUDE_MYSTACK_H_
