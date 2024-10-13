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
    return;
}

bool Queue::deQueue()
{
    Node *temp = front;
    if (isEmpty())
    {
        throw std::runtime_error("Queue is empty");
    }
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

void Queue::displayQueue()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty." << std::endl;
        return;
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
    return;
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

void Queue::clear(){
    if (isEmpty())
    {
        std::cout << "Queue is empty so no need to clear\n";
        return;
    }
    Node *temp = front;
    while(temp){
        Node *node_to_delete = temp;
        temp = temp->next;
        delete node_to_delete;
    }
    rear = nullptr;
    front = nullptr;
    std::cout<<"Queue cleared successfully!!"<<std::endl;
    return;

}

int Queue::peek()
{
    if (isEmpty())
    {
        throw std::runtime_error("Queue is empty");
    }
    return front->data;
}