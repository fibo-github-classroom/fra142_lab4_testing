#include "linked_list.h"

#include "gtest/gtest.h"

TEST(LinkedList, ConstructorTest) {
    EXPECT_NO_THROW(LinkedList());
}

TEST(LinkedList, SizeTest) {
    auto ll = LinkedList();
    EXPECT_EQ(ll.Size(), 0);
}

TEST(LinkedList, AppendTest) {
    auto ll = LinkedList();
    ll.Append(1);
    EXPECT_EQ(ll.Size(), 1);
    ll.Append(3);
    EXPECT_EQ(ll.Size(), 2);
    ll.Append(5);
    EXPECT_EQ(ll.Size(), 3);
    ll.Append(3);
    EXPECT_EQ(ll.Size(), 4);
    ll.Append(1);
    EXPECT_EQ(ll.Size(), 5);
}

class LinkedListTest : public testing::Test {
protected:
  void SetUp() override {
    ll_.Append(1);
    ll_.Append(3);
    ll_.Append(5);
    ll_.Append(3);
    ll_.Append(1);  
  }
  LinkedList ll_{};
};

TEST_F(LinkedListTest, StorageTest) {
    auto original_size = sizeof(ll_);
    ll_.Append(11);
    ll_.Append(12);
    ll_.Append(13);
    ll_.Append(13);
    EXPECT_EQ(sizeof(ll_), original_size);
}

TEST_F(LinkedListTest, CountTest) {
   EXPECT_EQ(ll_.Count(1),2);
   EXPECT_EQ(ll_.Count(2),0);
   EXPECT_EQ(ll_.Count(3),2);
   EXPECT_EQ(ll_.Count(5),1);
}

TEST_F(LinkedListTest, GetNodeTest) {
   EXPECT_EQ(ll_.GetNode(0).val,1);
   EXPECT_EQ(ll_.GetNode(0).next,&ll_.GetNode(1));
   EXPECT_EQ(ll_.GetNode(2).val,5);
   EXPECT_EQ(ll_.GetNode(2).next,&ll_.GetNode(3));
   EXPECT_EQ(ll_.GetNode(4).val,1);
   EXPECT_EQ(ll_.GetNode(4).next,nullptr);
}

TEST_F(LinkedListTest, GetMutableNodeTest) {    
   EXPECT_EQ(ll_.GetMutableNode(-1), nullptr);
   EXPECT_EQ(ll_.GetMutableNode(5), nullptr);
   Node* node = ll_.GetMutableNode(2);
   node->val = 11;
   EXPECT_EQ(ll_.GetMutableNode(2)->val, 11);
}

TEST_F(LinkedListTest, InsertTest) {
   ll_.Insert(0, 0);
   EXPECT_EQ(ll_.Size(), 6);
   EXPECT_EQ(ll_.GetNode(0).val, 0);
   ll_.Insert(-3, 5);
   EXPECT_EQ(ll_.Size(), 7);
   EXPECT_EQ(ll_.GetNode(5).val, -3);
   ASSERT_NE(ll_.GetNode(5).next, nullptr);
   EXPECT_EQ(ll_.GetNode(5).next->val, 1);
}


TEST_F(LinkedListTest, EraseAtTest) {
  EXPECT_TRUE(ll_.EraseAt(0));
  EXPECT_EQ(ll_.Size(), 4);
  EXPECT_FALSE(ll_.EraseAt(4));
  EXPECT_EQ(ll_.Size(), 4);
  EXPECT_TRUE(ll_.EraseAt(3));
  EXPECT_EQ(ll_.Size(), 3);
  EXPECT_EQ(ll_.GetNode(2).next, nullptr);
}


TEST_F(LinkedListTest, EraseTest) {    
  EXPECT_FALSE(ll_.Erase(0));
  EXPECT_EQ(ll_.Size(), 5);

  EXPECT_TRUE(ll_.Erase(5));
  EXPECT_EQ(ll_.Size(), 4);
  EXPECT_EQ(ll_.GetNode(0).val, 1);
  EXPECT_EQ(ll_.GetNode(1).val, 3);
  EXPECT_EQ(ll_.GetNode(2).val, 3);
  EXPECT_EQ(ll_.GetNode(3).val, 1);

  EXPECT_TRUE(ll_.Erase(1));
  EXPECT_EQ(ll_.Size(), 3);
  EXPECT_EQ(ll_.GetNode(0).val, 3);

  EXPECT_FALSE(ll_.Erase(5));
  EXPECT_EQ(ll_.Size(), 3);
}

TEST(LinkedList, EmptyListTest) {
   auto ll = LinkedList();
   EXPECT_EQ(ll.Count(1), 0);
   EXPECT_EQ(ll.GetMutableNode(0), nullptr);
   EXPECT_FALSE(ll.Erase(0));
   EXPECT_FALSE(ll.EraseAt(0));
   ll.Insert(-1, 1);
   EXPECT_EQ(ll.Size(), 1);
   EXPECT_EQ(ll.GetNode(0).val, -1);
   EXPECT_EQ(ll.GetNode(0).next, nullptr);
}

