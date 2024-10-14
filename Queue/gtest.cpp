// gtest.cpp

#include "Queue.h"
#include <gtest/gtest.h>
#include <stdexcept> // For std::runtime_error

// Test enqueue
TEST(QueueTest, Enqueue) {
    Queue queue;
    queue.enQueue(5);
    EXPECT_EQ(queue.peek(), 5);
    queue.enQueue(10);
    EXPECT_EQ(queue.peek(), 5);
}

// Test dequeue
TEST(QueueTest, Dequeue) {
    Queue queue;
    queue.enQueue(5);
    queue.enQueue(10);
    EXPECT_TRUE(queue.deQueue());
    EXPECT_EQ(queue.peek(), 10);
    EXPECT_TRUE(queue.deQueue());
    EXPECT_THROW(queue.peek(), std::runtime_error);  // Expect an error when trying to peek an empty queue
}

// Test size
TEST(QueueTest, Size) {
    Queue queue;
    queue.enQueue(5);
    queue.enQueue(10);
    EXPECT_EQ(queue.size(), 2);
    queue.deQueue();
    EXPECT_EQ(queue.size(), 1);
}

// Test clear
TEST(QueueTest, Clear) {
    Queue queue;
    queue.enQueue(5);
    queue.enQueue(10);
    EXPECT_TRUE(queue.clear());
    EXPECT_EQ(queue.size(), 0);
    EXPECT_TRUE(queue.isEmpty());
}

// Test clear on an already empty queue
TEST(QueueTest, ClearEmptyQueue) {
    Queue queue;
    // First, clear to ensure the queue is empty
    queue.clear();
    // Now, attempting to clear again should return false
    EXPECT_FALSE(queue.clear());
}

// Test multiple enqueues and dequeues
TEST(QueueTest, MultipleEnqueueDequeue) {
    Queue queue;
    for(int i = 1; i <= 100; ++i) {
        queue.enQueue(i);
    }
    EXPECT_EQ(queue.size(), 100);
    for(int i = 1; i <= 100; ++i) {
        EXPECT_EQ(queue.peek(), i);
        EXPECT_TRUE(queue.deQueue());
    }
    EXPECT_TRUE(queue.isEmpty());
}

// Test dequeue on an empty queue
TEST(QueueTest, DequeueEmptyQueue) {
    Queue queue;
    EXPECT_THROW(queue.deQueue(), std::runtime_error);
}
