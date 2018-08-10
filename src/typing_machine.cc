// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
  this->headNode = new Node('H');
  this->cursorNode = this->headNode;
  this->tailNode = this->cursorNode->InsertNextNode('T');
  stringCount = 0;
}

void TypingMachine::HomeKey() {
  this->cursorNode = this->headNode;
}

void TypingMachine::EndKey() {
  this->cursorNode = this->tailNode->GetPreviousNode();
}

void TypingMachine::LeftKey() {
  if (this->cursorNode != this->headNode) {
    this->cursorNode = this->cursorNode->GetPreviousNode();
  }
}

void TypingMachine::RightKey() {
  if (this->cursorNode->GetNextNode() != this->tailNode) {
    this->cursorNode = this->cursorNode->GetNextNode();
  }
}

bool TypingMachine::TypeKey(char key) {
  if (key < 32 || key > 126) return false;
  if (stringCount >= 100) return false;
  this->cursorNode = this->cursorNode->InsertNextNode(key);
  stringCount++;
  return true;
}

bool TypingMachine::EraseKey() {
  if (this->cursorNode == this->headNode) return false;
  this->cursorNode = this->cursorNode->GetPreviousNode();
  this->cursorNode->EraseNextNode();
  stringCount--;
  return true;
}

std::string TypingMachine::Print(char separator) {
  std::string result = "";

  Node* currentNode = this->headNode;
  if (currentNode == this->cursorNode && separator != '\0') {
	  result.push_back(separator);
  }
  currentNode = currentNode->GetNextNode();
  while (currentNode != this->tailNode) {
	  result.push_back(currentNode->GetData());
	  if (currentNode == this->cursorNode && separator != '\0') {
		  result.push_back(separator);
	  }
	  currentNode = currentNode->GetNextNode();
  }
  return result;
}
