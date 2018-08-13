// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
  headNode = new Node('H');
  tailNode = headNode->InsertNextNode('T');
  cursorNode = headNode;
  stringCount = 0;
}

void TypingMachine::HomeKey() {
  cursorNode = headNode;
}

void TypingMachine::EndKey() {
  cursorNode = tailNode->GetPreviousNode();
}

void TypingMachine::LeftKey() {
  if (cursorNode != headNode) {
    cursorNode = cursorNode->GetPreviousNode();
  }
}

void TypingMachine::RightKey() {
  if (cursorNode->GetNextNode() != tailNode) {
    cursorNode = cursorNode->GetNextNode();
  }
}

bool TypingMachine::TypeKey(char key) {
  if (key < ASCII_RANGE_START || key > ASCII_RANGE_END) return false;
  if (stringCount >= MAX_LENGTH) return false;

  cursorNode = cursorNode->InsertNextNode(key);
  stringCount++;
  return true;
}

bool TypingMachine::EraseKey() {
  if (cursorNode == headNode) return false;

  cursorNode = cursorNode->GetPreviousNode();
  cursorNode->EraseNextNode();
  stringCount--;
  return true;
}

std::string TypingMachine::Print(char separator) {
  if (separator == '\0') {
    return PrintWithoutSeparator();
  }
  else {
    return PrintWithSeparator(separator);
  }
}

std::string TypingMachine::PrintWithoutSeparator() {
  std::string result = "";

  Node* currentNode = headNode->GetNextNode();
  while (currentNode != tailNode) {
    result.push_back(currentNode->GetData());
    currentNode = currentNode->GetNextNode();
  }
  return result;
}

std::string TypingMachine::PrintWithSeparator(char separator) {
  std::string result = "";

  Node* currentNode = headNode;
  while (currentNode != tailNode) {
    if (currentNode != headNode) {
      result.push_back(currentNode->GetData());
    }
    if (currentNode == cursorNode) {
      result.push_back(separator);
    }
    currentNode = currentNode->GetNextNode();
  }
  return result;
}
