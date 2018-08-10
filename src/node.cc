// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
  this->data = data;
  this->previousNode = nullptr;
  this->nextNode = nullptr;
}

char Node::GetData() {
  return data;
}

Node* Node::GetPreviousNode() {
  if (previousNode != nullptr) return previousNode;
  return nullptr;
}

Node* Node::GetNextNode() {
  if (nextNode != nullptr) return nextNode;
  return nullptr;
}

Node* Node::InsertPreviousNode(char data) {
  Node* newNode = new Node(data);
  if (this->previousNode != nullptr) {
    newNode->previousNode = this->previousNode;
    this->previousNode->nextNode = newNode;
  }
  newNode->nextNode = this;
  this->previousNode = newNode;

  return newNode;
}

Node* Node::InsertNextNode(char data) {
  Node* newNode = new Node(data);
  if (this->nextNode != nullptr) {
	newNode->nextNode = this->nextNode;
	this->nextNode->previousNode = newNode;
  }
  newNode->previousNode = this;
  this->nextNode = newNode;

  return newNode;
}

bool Node::ErasePreviousNode() {
  if (this->previousNode == nullptr) return false;
  Node* deleteNode = this->previousNode;
  if (deleteNode->previousNode != nullptr) {
    deleteNode->previousNode->nextNode = this;
  }
  this->previousNode = deleteNode->previousNode;
  delete deleteNode;

  return true;
}

bool Node::EraseNextNode() {
  if (this->nextNode == nullptr) return false;
  Node* deleteNode = this->nextNode;
  if (deleteNode->nextNode != nullptr) {
	  deleteNode->nextNode->previousNode = this;
  }
  this->nextNode = deleteNode->nextNode;
  delete deleteNode;

  return true;
}
