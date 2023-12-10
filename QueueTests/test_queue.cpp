#include "../Queue/TQueue.h"
#include "gtest.h"

//TEST(TQueue, can_create_queue_with_positive_size)
//{
//    ASSERT_NO_THROW(TQueue<int> q(5));
//}
//
//TEST(TQueue, throws_when_create_queue_with_negative_size)
//{
//	ASSERT_ANY_THROW(TQueue<int> q(-5));
//}

TEST(TQueue, can_create_copied_queue)
{
	TQueue<int> q(5);
	int i = 1;
	while (!(q.full()))
	{
		q.Push(i);
		i++;
	}
	ASSERT_NO_THROW(TQueue<int> q1(q));
}

TEST(TQueue, copied_queue_is_equal_to_source_one)
{
	TQueue<int> q(5);
	int i = 1;
	while (!(q.full()))
	{
		q.Push(i);
		i++;
	}
	TQueue<int> q1(q);
	while (!(q.empty()) && !(q1.empty()))
	{
		EXPECT_EQ(q.Pop(), q1.Pop());
	}
}
