#include "node.h"

#include "gtest/gtest.h"
#include <iostream>

TEST(NodeTest, CreateNode) {
  EXPECT_NO_THROW(Node());
  auto n = CreateNode(3);
  EXPECT_NE(n, nullptr);
  EXPECT_EQ(n->val, 3);
  EXPECT_EQ(n->next, nullptr);
}

TEST(NodeTest, CreateNode2) {
  Node a = Node{.val = 20};
  auto n = CreateNode(10, &a);
  EXPECT_NE(n, nullptr);
  EXPECT_EQ(n->val, 10);
  EXPECT_EQ(n->next, &a);
}

TEST(NodeTest, FreeNode) {
  for(int i = 0; i < 1000000; ++i) {
    Node* n = CreateNode(i);
    FreeNode(n);
  }
}
