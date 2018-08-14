// Copyright 2018 sjh.yoo

#ifndef TYPING_MACHINE_H_
#define TYPING_MACHINE_H_

#include <string>

#include "node.h"

class TypingMachine {
 private:
  Node* headNode;
  Node* tailNode;
  Node* cursorNode;
  int stringCount;
  const int ASCII_RANGE_START = 32;
  const int ASCII_RANGE_END = 126;
  const int MAX_LENGTH = 100;

 public:
  TypingMachine();
  void HomeKey();
  void EndKey();
  void LeftKey();
  void RightKey();
  bool TypeKey(char key);
  bool EraseKey();
  std::string Print(char separator);
};

#endif  // TYPING_MACHINE_H_
