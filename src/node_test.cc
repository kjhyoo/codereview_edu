// Copyright 2018 Minkyu Jo

#include "node.h"
#include "node_test.h"
#include "test.h"

class NodeConstructorTestSuite
{
private:
  static void SingleNodeTest() {
    Node *node = new Node('A');
    EXPECT_TRUE(node->GetPreviousNode() == nullptr);
    EXPECT_TRUE(node->GetNextNode() == nullptr);
    ASSERT_EQ(node->GetData(), 'A');
    delete node;
  }

public:
  static void RunTest() {
    SingleNodeTest();
  }
};

class InsertNodeTestSuite
{
private:
  static void InsertPreviousNodeAtSingleNodeTest() {
    Node *node = new Node('A');
    Node *previousNode = node->InsertPreviousNode('P');

    EXPECT_TRUE(previousNode->GetPreviousNode() == nullptr);
    EXPECT_TRUE(previousNode->GetNextNode() == node);
    EXPECT_TRUE(node->GetPreviousNode() == previousNode);
    EXPECT_TRUE(node->GetNextNode() == nullptr);
    ASSERT_EQ(previousNode->GetData(), 'P');
    ASSERT_EQ(node->GetData(), 'A');

    delete node;
    delete previousNode;
  }

  static void InsertPreviousNodeAtMultiNodeTest() {
    Node *thirdNode = new Node('3');
    Node *firstNode = thirdNode->InsertPreviousNode('1');
    Node *secondNode = thirdNode->InsertPreviousNode('2');

    EXPECT_TRUE(firstNode->GetPreviousNode() == nullptr);
    EXPECT_TRUE(firstNode->GetNextNode() == secondNode);
    EXPECT_TRUE(secondNode->GetPreviousNode() == firstNode);
    EXPECT_TRUE(secondNode->GetNextNode() == thirdNode);
    EXPECT_TRUE(thirdNode->GetPreviousNode() == secondNode);
    EXPECT_TRUE(thirdNode->GetNextNode() == nullptr);
    ASSERT_EQ(firstNode->GetData(), '1');
    ASSERT_EQ(secondNode->GetData(), '2');
    ASSERT_EQ(thirdNode->GetData(), '3');

    delete firstNode;
    delete secondNode;
    delete thirdNode;
  }

  static void InsertNextNodeAtSingleNodeTest() {
    Node *node = new Node('A');
    Node *nextNode = node->InsertNextNode('N');

    EXPECT_TRUE(node->GetPreviousNode() == nullptr);
    EXPECT_TRUE(node->GetNextNode() == nextNode);
    EXPECT_TRUE(nextNode->GetPreviousNode() == node);
    EXPECT_TRUE(nextNode->GetNextNode() == nullptr);
    ASSERT_EQ(node->GetData(), 'A');
    ASSERT_EQ(nextNode->GetData(), 'N');

    delete node;
    delete nextNode;
  }

  static void InsertNextNodeAtMultiNodeTest() {
    Node *firstNode = new Node('1');
    Node *thirdNode = firstNode->InsertNextNode('3');
    Node *secondNode = firstNode->InsertNextNode('2');

    EXPECT_TRUE(firstNode->GetPreviousNode() == nullptr);
    EXPECT_TRUE(firstNode->GetNextNode() == secondNode);
    EXPECT_TRUE(secondNode->GetPreviousNode() == firstNode);
    EXPECT_TRUE(secondNode->GetNextNode() == thirdNode);
    EXPECT_TRUE(thirdNode->GetPreviousNode() == secondNode);
    EXPECT_TRUE(thirdNode->GetNextNode() == nullptr);
    ASSERT_EQ(firstNode->GetData(), '1');
    ASSERT_EQ(secondNode->GetData(), '2');
    ASSERT_EQ(thirdNode->GetData(), '3');

    delete firstNode;
    delete secondNode;
    delete thirdNode;
  }

public:
  static void RunTest() {
    InsertPreviousNodeAtSingleNodeTest();
    InsertPreviousNodeAtMultiNodeTest();
    InsertNextNodeAtSingleNodeTest();
    InsertNextNodeAtMultiNodeTest();
  }
};

class GetNodeTestSuite
{
private:
  static void GetPreviousNodeFromSingleNodeTest() {
    Node *node = new Node('A');
    ASSERT_TRUE(node->GetPreviousNode() == nullptr);
    delete node;
  }

  static void GetPreviousNodeFromMultiNodeTest() {
    Node *node = new Node('A');
    Node *previousNode = node->InsertPreviousNode('P');
    ASSERT_TRUE(node->GetPreviousNode() == previousNode);
    delete node;
    delete previousNode;
  }

  static void GetNextNodeFromSingleNodeTest() {
    Node *node = new Node('A');
    ASSERT_TRUE(node->GetNextNode() == nullptr);
    delete node;
  }

  static void GetNextNodeFromMultiNodeTest() {
    Node *node = new Node('A');
    Node *nextNode = node->InsertNextNode('N');
    ASSERT_TRUE(node->GetNextNode() == nextNode);
    delete node;
    delete nextNode;
  }

public:
  static void RunTest() {
    GetPreviousNodeFromSingleNodeTest();
    GetPreviousNodeFromMultiNodeTest();
    GetNextNodeFromSingleNodeTest();
    GetNextNodeFromMultiNodeTest();
  }
};

class EraseNodeTestSuite
{
private:
  static void ErasePreviousNodeFromSingleNodeTest() {
    Node *node = new Node('A');
    ASSERT_FALSE(node->ErasePreviousNode());
    delete node;
  }

  static void ErasePreviousNodeFromDoubleNodeTest() {
    Node *node = new Node('A');
    node->InsertPreviousNode('P');

    ASSERT_TRUE(node->ErasePreviousNode());
    // need deletion test
    EXPECT_TRUE(node->GetPreviousNode() == nullptr);
    EXPECT_TRUE(node->GetNextNode() == nullptr);
    EXPECT_EQ(node->GetData(), 'A');

    delete node;
  }

  static void ErasePreviousNodeFromMultiNodeTest() {
    Node *thirdNode = new Node('3');
    Node *firstNode = thirdNode->InsertPreviousNode('1');
    thirdNode->InsertPreviousNode('2');

    ASSERT_TRUE(thirdNode->ErasePreviousNode());
    EXPECT_TRUE(firstNode->GetPreviousNode() == nullptr);
    EXPECT_TRUE(firstNode->GetNextNode() == thirdNode);
    EXPECT_TRUE(thirdNode->GetPreviousNode() == firstNode);
    EXPECT_TRUE(thirdNode->GetNextNode() == nullptr);
    EXPECT_EQ(firstNode->GetData(), '1');
    EXPECT_EQ(thirdNode->GetData(), '3');

    delete firstNode;
    delete thirdNode;
  }

  static void EraseNextNodeFromSingleNodeTest() {
    Node *node = new Node('A');
    ASSERT_FALSE(node->EraseNextNode());
    delete node;
  }

  static void EraseNextNodeFromDoubleNodeTest() {
    Node *node = new Node('A');
    node->InsertNextNode('N');

    ASSERT_TRUE(node->EraseNextNode());
    // need deletion test
    EXPECT_TRUE(node->GetPreviousNode() == nullptr);
    EXPECT_TRUE(node->GetNextNode() == nullptr);
    EXPECT_EQ(node->GetData(), 'A');

    delete node;
  }

  static void EraseNextNodeFromMultiNodeTest() {

    Node *firstNode = new Node('1');
    Node *thirdNode = firstNode->InsertNextNode('3');
    firstNode->InsertNextNode('2');

    ASSERT_TRUE(firstNode->EraseNextNode());
    EXPECT_TRUE(firstNode->GetPreviousNode() == nullptr);
    EXPECT_TRUE(firstNode->GetNextNode() == thirdNode);
    EXPECT_TRUE(thirdNode->GetPreviousNode() == firstNode);
    EXPECT_TRUE(thirdNode->GetNextNode() == nullptr);
    ASSERT_EQ(firstNode->GetData(), '1');
    ASSERT_EQ(thirdNode->GetData(), '3');

    delete firstNode;
    delete thirdNode;
  }

public:
  static void RunTest() {
    ErasePreviousNodeFromSingleNodeTest();
    ErasePreviousNodeFromDoubleNodeTest();
    ErasePreviousNodeFromMultiNodeTest();
    EraseNextNodeFromSingleNodeTest();
    EraseNextNodeFromDoubleNodeTest();
    EraseNextNodeFromMultiNodeTest();
  }
};

void NodeTest() {
  NodeConstructorTestSuite::RunTest();
  InsertNodeTestSuite::RunTest();
  GetNodeTestSuite::RunTest();
  EraseNodeTestSuite::RunTest();
}