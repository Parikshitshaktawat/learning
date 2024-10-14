#pragma once

struct Node{
    int data;
    Node *next;
};


class Queue
{
private:
    Node *front;
    Node *rear;
public:

    /**
     * @brief Construct a new Queue object
     * 
     */
    Queue();

    /**
     * @brief Destroy the Queue object
     * 
     */
    ~Queue();


    /**
     * @brief Add value at last of queue
     * 
     * @param value Takes the data to insert
     */
    void enQueue(int value);


    /**
     * @brief Removes the data from front according to FIFO rule
     * 
     * @return true Returns true if success
     * @return false Returns false if failed
     */
    bool deQueue();


    /**
     * @brief IT returns the queue is empty or not
     * 
     * @return true If empty
     * @return false If not empty
     */
    bool isEmpty();


    /**
     * @brief Displays the whole queue
     * 
     * @return true If success
     * @return false If queue is empty
     */
    bool displayQueue();


    /**
     * @brief To view the first element in queue
     * 
     * @return int It returns the value in front node
     */
    int peek();


    /**
     * @brief It returns the size of queue
     * 
     * @return int Returns size
     */
    int size();


    /**
     * @brief It will clear the queue
     * 
     * @return true If success
     * @return false If faliled
     */
    bool clear();
};


