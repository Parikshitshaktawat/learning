/**
 * @file Queue.cpp
 * @author Parikshit Shaktawat (parikshitshaktawat.it@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-10-13
 *
 * @copyright Copyright (c) 2024
 *
 */


#include "Queue.h"
#include <iostream>

Queue::Queue() : front(nullptr), rear(nullptr) {};

Queue::~Queue()
{
    clear();
}

void Queue::enQueue(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    if (isEmpty())
    {   
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;

    return;
}

bool Queue::deQueue()
{
    if (isEmpty())
    {
        throw std::runtime_error("Queue is empty");
    }
    Node *temp = front;
    front = front->next;
    delete temp;
    if (front == nullptr)
    {
        rear = nullptr;
    }
    return true;
}

bool Queue::isEmpty()
{
    return (!rear && !front);
}

bool Queue::displayQueue()
{
    if (isEmpty())
    {
        throw std::runtime_error("Queue is empty");
    }
    Node *temp = front;
    std::cout << "Queue elements: ";
    while (temp)
    {
        std::cout << temp->data ;
        if (temp->next)
        {
            std::cout << " ->" ;
        }
        temp = temp->next;
    }
    return true;
}

int Queue::size(){
    if (isEmpty())
    {
        return 0;
    }
    Node *temp = front;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;

    
}

bool Queue::clear(){
    if (isEmpty())
    {
        return false;
    }
    Node *temp = front;
    while(temp){
        Node *node_to_delete = temp;
        temp = temp->next;
        delete node_to_delete;
    }
    rear = nullptr;
    front = nullptr;
    return true;

}

int Queue::peek()
{
    if (isEmpty())
    {
        throw std::runtime_error("Queue is empty");
    }
    return front->data;
}