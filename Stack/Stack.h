#pragma once

struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:

    Stack();

    ~Stack();


    /**
     * @brief Checks for the stack is empty or not
     * 
     * @return true If empty
     * @return false If not empty
     */
    bool isEmpty();



    /**
     * @brief To insert data in stack
     * 
     * @param data Takes the data
     * @return true If pushed
     * @return false If not pushed
     */
    bool push(int data);



    /**
     * @brief To remove data from stack
     * 
     * @return true If removal is successfull
     * @return false If removal failed
     */
    bool pop();



    /**
     * @brief To view the value on top
     * 
     * @return Returns the int value which is on the top
     */
    int peak();



    /**
     * @brief To check the size of stack
     * 
     * @return Returns the size
     */
    int size();
};