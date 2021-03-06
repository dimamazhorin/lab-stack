//
// Created by dima on 15.03.2021.
//
// INCLUDE FIRST_STACK_HPP_
#include <cstring>
#include <utility>

#include "iostream"


template <typename T>
class Stack {
 public:
  Stack() : m_memp(new T[16]), m_head(0), m_stackSize(16) {}
  Stack(Stack&& stack) {
    m_head = stack.m_head;
    m_memp = stack.m_memp;
    m_stackSize = stack.m_stackSize;
    stack.m_memp = nullptr;
  }
  Stack(const Stack&) = delete;  // test

  void push(T&& value) {
    if (m_head == m_stackSize) {
      T* tmp = new T[m_stackSize * 2];
      if (tmp != nullptr) {
        std::memcpy(tmp, m_memp, m_stackSize * sizeof(T));
        m_stackSize = m_stackSize * 2;
        delete[]m_memp;
        m_memp = tmp;
      } else {
        throw "No memory for element";
      }
    }
    m_memp[m_head] = value;
    m_head += 1;
  }

  void push(const T& value) {
    if (m_head == m_stackSize) {
      T* tmp = new T[m_stackSize * 2];
      if (tmp != nullptr) {
        std::memcpy(tmp, m_memp, m_stackSize * sizeof(T));
        m_stackSize = m_stackSize * 2;
        delete[]m_memp;
        m_memp = tmp;
      } else {
        throw "No memory for element";
      }
    }
    m_memp[m_head] = value;
    m_head += 1;
  }
  void pop() {
    if (m_head == 0) {
      throw std::out_of_range{"Empty stack"};
    }
    m_head -= 1;
  }
  const T& head() const {
    if (m_head == 0) {
      throw std::out_of_range{"Stack is empty"};
    }
    return m_memp[m_head - 1];
  }
  ~Stack() { delete[] m_memp; }

 private:
  T* m_memp;
  int m_head;
  int m_stackSize;
};