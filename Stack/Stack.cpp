/**
 * @file Stack.cpp
 * @author Parikshit Shaktawat (parikshitshaktawat.it@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-10-13
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "Stack.h"
#include <iostream>

Stack::Stack() : top(nullptr) {};

Stack::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}

bool Stack::isEmpty()
{
    return top == nullptr;
}

bool Stack::pop()
{
    if (isEmpty())
    {
        throw std::runtime_error("Stack is empty..");
    }
    Node *tempNode = top;
    top = top->next;
    delete tempNode;
    return true;
}

bool Stack::push(int data)
{
    Node *newNode = new Node();
    newNode->next = top;
    newNode->data = data;
    top = newNode;
    return true;
}

int Stack::size()
{
    if (isEmpty())
    {
        return 0;
    }
    int count = 0;
    Node *tempNode = top;
    while (tempNode)
    {
        count++;
        tempNode = tempNode->next;
    }
    return count;
}

int Stack::peak()
{
    if (isEmpty())
    {
        throw std::runtime_error("Stack is empty..");
    }
    return top->data;
}

bool Stack::clear()
{
    if (isEmpty())
    {
        throw std::runtime_error("Stack is empty..");
    }
    while (top)
    {
        pop();
    }
    return true;
}

void Stack::traverse()
{
    if (isEmpty())
    {
        throw std::runtime_error("Stack is empty..");
    }
    Node *temp = top;
    std::cout << "< ";
    while (temp)
    {
        std::cout << temp->data ;
        if (temp->next) {
            std::cout << ", ";  
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}