#include "../Queue_on_ForwardList/TLQueue.h"
#include "gtest.h"

TEST(TLQueue, can_create_queue_with_positive_size)
{
    ASSERT_NO_THROW(TLQueue<int> q);
}

TEST(TLQueue, new_queue_is_empty)
{
    TLQueue<int> q;
    EXPECT_EQ(1, q.empty());
}

TEST(TLQueue, copied_queue_is_equal_to_source_one)
{
    TLQueue<int> q;
    q.Push(1);
    q.Push(2);
    q.Push(3);
    ASSERT_NO_THROW(TLQueue<int> q1(q));
    TLQueue<int> q1(q);
    EXPECT_EQ(1, q == q1);
}

TEST(TLQueue, return_true_when_compare_two_equal_queues)
{
    TLQueue<int> q;
    q.Push(1);
    q.Push(2);
    q.Push(3);
    TLQueue<int> q1;
    q1.Push(1);
    q1.Push(2);
    q1.Push(3);
    EXPECT_EQ(1, q == q1);
}

TEST(TLQueue, return_false_when_compare_two_equal_queues)
{
    TLQueue<int> q;
    q.Push(1);
    q.Push(2);
    TLQueue<int> q1;
    q1.Push(1);
    q1.Push(1);
    q1.Push(1);
    EXPECT_EQ(1, q != q1);
}

TEST(TLQueue, can_push)
{
    TLQueue<int> q;
    int a1 = 1;
    int a2 = 2;
    int a3 = 3;
    //SERT_NO_THROW(q.Push(a1));
    //ASSERT_NO_THROW(q.Push(a2));
   // ASSERT_NO_THROW(q.Push(a3));
    q.Push(a1);
    q.Push(a2);
    q.Push(a3);
    EXPECT_EQ(a1,q.Pop());
    EXPECT_EQ(a2,q.Pop());
    EXPECT_EQ(a3,q.Pop());
}

TEST(TLQueue, can_pop)
{
    TLQueue<int> q;
    int a1 = 1;
    int a2 = 2;
    int a3 = 3;
    q.Push(a1);
    q.Push(a2);
    q.Push(a3);
    int b1, b2, b3;
    ASSERT_NO_THROW(b1 = q.Pop());
    ASSERT_NO_THROW(b2 = q.Pop());
    ASSERT_NO_THROW(b3 = q.Pop());
    EXPECT_EQ(a1, b1);
    EXPECT_EQ(a2, b2);
    EXPECT_EQ(a3, b3);
}

TEST(TLQueue, throws_when_use_pop_on_empty_queue)
{
    TLQueue<int> q;
    ASSERT_ANY_THROW(q.Pop());
}

TEST(TLQueue, can_use_front_and_back)
{

    TLQueue<int> q;
    q.Push(1);
    int b1, b2;
    ASSERT_NO_THROW(b1 = q.Front());
    ASSERT_NO_THROW(b2 = q.Back());
    EXPECT_EQ(b1, b2);

}
TEST(TLQueue, throws_when_use_front_or_back_on_empty_queue)
{
    TLQueue<int> q;
    ASSERT_ANY_THROW(q.Front());
    ASSERT_ANY_THROW(q.Back());
}

TEST(TLQueue, return_true_when_use_Empty_on_empty_queue)
{
    TLQueue<int> q;
    bool b1 = q.empty();
    EXPECT_EQ(1, b1);
}
TEST(TLQueue, return_false_when_use_Empty_on_not_empty_queue)
{
    TLQueue<int> q;
    q.Push(1);
    q.Push(1);
    bool b1 = q.empty();
    EXPECT_EQ(0, b1);
}

TEST(TLQueue, can_get_number_of_elements)
{
    TLQueue<int> q;
    EXPECT_EQ(0, q.ElementsNumber());
}