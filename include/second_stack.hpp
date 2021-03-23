// Copyright 2020 <dmitrymazhorinjr@gmail.com>
INCLUDE SECOND_STACK_HPP_
#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_


#include "cstring"
#include "iostream"
template <typename T>
class SStack {
 public:
  SStack() : m_memp(new T[16]), m_head(0), m_stackSize(16) {}
  SStack(SStack&& stack){
    m_head = stack.m_head;
    m_memp = stack.m_memp;
    m_stackSize = stack.m_stackSize;
    stack.m_memp = nullptr;
  }
  template <typename... Args>
  void push_emplace(Args&&... value) {
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
    m_memp[m_head] = T(value...);
    m_head += 1;
  }
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
    m_memp[m_head] = std::move(value);
    m_head += 1;
  }
  const T& head() const {
    if (m_head == 0) {
      throw std::out_of_range{"Stack is empty"};
    }

    return m_memp[m_head - 1];
  }
  T pop() {
    if (m_head == 0) {
      throw std::out_of_range{"Empty array"};
    }
    m_head-=1;
    return m_memp[m_head];
  }
  ~SStack() { delete[] m_memp; }

 private:
  T* m_memp;
  int m_head;
  int m_stackSize;
};
#endif // INCLUDE_HEADER_HPP_