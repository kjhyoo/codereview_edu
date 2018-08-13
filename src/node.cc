// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
  this->data = data;
  previousNode = nullptr;
  nextNode = nullptr;
}

char Node::GetData() {
  return data;
}

Node* Node::GetPreviousNode() {
  if (previousNode == nullptr) return nullptr;
  return previousNode;
}

Node* Node::GetNextNode() {
  if (nextNode == nullptr) return nullptr;
  return nextNode;
}

Node* Node::InsertPreviousNode(char data) {
  Node* newNode = new Node(data);
  newNode->previousNode = previousNode;
  newNode->nextNode = this;
  
  if (previousNode != nullptr) {
    previousNode->nextNode = newNode;
  }
  previousNode = newNode;

  return newNode;
}

Node* Node::InsertNextNode(char data) {
  Node* newNode = new Node(data);
  newNode->previousNode = this;
  newNode->nextNode = nextNode;

  if (nextNode != nullptr) {
    nextNode->previousNode = newNode;
  }
  nextNode = newNode;

  return newNode;
}

bool Node::ErasePreviousNode() {
  if (previousNode == nullptr) return false;

  Node* deleteNode = previousNode;
  if (deleteNode->previousNode != nullptr) {
    deleteNode->previousNode->nextNode = this;
  }
  previousNode = deleteNode->previousNode;
  delete deleteNode;

  return true;
}

bool Node::EraseNextNode() {
  if (nextNode == nullptr) return false;

  Node* deleteNode = nextNode;
  if (deleteNode->nextNode != nullptr) {
	  deleteNode->nextNode->previousNode = this;
  }
  nextNode = deleteNode->nextNode;
  delete deleteNode;

  return true;
}
