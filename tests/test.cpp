// Copyright 2020 dima <dmitrymazhorinjr@gmail.com>

#include <gtest/gtest.h>

#include "first_stack.hpp"
#include "iostream"
#include "second_stack.hpp"

TEST(simpleStack, constrWithNoArgument) {
  Stack<int> stackObj;
  int k = 5;
  int m = 10;
  stackObj.push(k);
  stackObj.push(m);
  ASSERT_EQ(stackObj.head(), 10);
}

TEST(simpleStack, constrWithRValue) {
  Stack<int> stackObj;
  stackObj.push(8);
  Stack<int> stack = Stack(std::move(stackObj));
  ASSERT_EQ(stack.head(), 8);
}

TEST(simpleStack, pushRValue) {
  Stack<int> stackObj;
  stackObj.push(std::move(8));
  stackObj.push(std::move(4));
  ASSERT_EQ(stackObj.head(), 4);
}

TEST(simpleStack, pushLValue) {
  Stack<int> stackObj;
  int k = 3;
  int a = 18;
  stackObj.push(k);
  stackObj.push(a);
  ASSERT_EQ(stackObj.head(), 18);
}

TEST(simpleStack, pop) {
  Stack<int> stackObj;
  int k = 3;
  int a = 18;
  stackObj.push(k);
  stackObj.push(a);
  stackObj.pop();
  ASSERT_EQ(stackObj.head(), 3);
}

TEST(simpleStack, popEmpty) {
  Stack<int> stackObj;
  ASSERT_THROW(stackObj.pop(), std::out_of_range);
}

TEST(simpleStack, headEmpty) {
  Stack<int> stackObj;
  ASSERT_THROW(stackObj.head(), std::out_of_range);
}

TEST(simpleStack, stackExpansion) {
  Stack<int> stackObj;
  for (int i=0;i<30;++i){
    stackObj.push(std::move(i));
  }
  ASSERT_EQ(stackObj.head(), 29);
}

TEST(hardStack, pushEmplace) {
  SStack<int> stackObj;
  stackObj.push_emplace(4);
  ASSERT_EQ(stackObj.head(), 4);
}

TEST(hardStack, push) {
  SStack<int> stackObj;
  stackObj.push(9);
  ASSERT_EQ(stackObj.head(), 9);
}

TEST(hardStack, pop) {
  SStack<int> stackObj;
  stackObj.push(9);
  stackObj.push(4);
  stackObj.pop();
  ASSERT_EQ(stackObj.head(), 9);
}

TEST(hardStack, headEmpty) {
  SStack<int> stackObj;
  ASSERT_THROW(stackObj.head(), std::out_of_range);
}

TEST(hardStack, popEmptyStack) {
  SStack<int> stackObj;
  ASSERT_THROW(stackObj.pop(), std::out_of_range);
}

TEST(hardStack, stackExpansion) {
  SStack<int> stackObj;
  for (int i=0;i<31;++i){
    stackObj.push(std::move(i));
  }
  ASSERT_EQ(stackObj.head(), 30);
}

TEST(hardStack, constr) {
  SStack<int> stackObj;
  stackObj.push(8);
  SStack<int> stack = SStack(std::move(stackObj));
  ASSERT_EQ(stack.head(), 8);
}
