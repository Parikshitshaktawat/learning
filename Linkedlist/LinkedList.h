#pragma once

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{

private:
    Node *head;

public:

    // Constructor to initialize the linked list
    LinkedList();

    // Destructor to free allocated memory
    ~LinkedList();


    /**
     * @brief It prints all the value in linked list
     */
    void printList();

    /**
     * @brief It will add node at end and if the linked list is empty then add a node
     * @param data Takes the value which you want to insert
     */
    void createNode(int data);

    /**
     * @brief This function will delete the stating node
     *
     */
    bool deleteFromBeginning();

    /**
     * @brief It delete the node from the list
     * @param position It is the position which you want to delete
     */
    bool deleteDataAtPosition(int position);

    /**
     * @brief To delete the particular value
     * @param value It takes the values which you want to delete
     */
    bool deleteByValue(int value);

    /**
     * @brief To search the particular value in list
     *
     * @param value It takes the value which you want to search
     */
    int searchElement(int value);

    /**
     * @brief This function will reverse the list without using another list
     * 
     */
    void reverseList();


    /**
     * @brief This function find the loop in linked list using hash map if there is loop returns true else false
     * 
     * @return true 
     * @return false 
     */
    bool detectLoopUsingHashMap();
    
    /**
     * @brief This function find loop in linked list using two pointer approach,
     * The approach is there are two pointer one is slow and one is fast,
     * slow moves one step and fast moves two step if both meets at any point
     * then we can say that there is loop in linked list 
     * 
     * @return true 
     * @return false 
     */
    bool detectLoopUsingFloydAlgo();


};

