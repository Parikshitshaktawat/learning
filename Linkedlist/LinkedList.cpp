/**
 * @file LinkedList.cpp
 * @author Parikshit Shaktawat (parikshitshaktawat.it@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-10-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "LinkedList.h"
#include <iostream>
#include <unordered_set>

// Constructor
LinkedList::LinkedList() : head(nullptr) {}

// Destructor
LinkedList::~LinkedList()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void LinkedList::createNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->next = nullptr;

    // If the list is empty, update the head to the new node
    if (!head)
    {
        head = node;
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = node;
}

void LinkedList::printList()
{
    if (!head)
    {
        std::cout << "< List is empty.. >" << std::endl;
        return;
    }
    Node *temp = head;
    std::cout << "< ";

    while (temp)
    {

        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << ">" << std::endl;
    return;
}

bool LinkedList::deleteFromBeginning()
{
    if (!head)
    {
        std::cout << "List is empty." << std::endl;
        return false;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        std::cout << "List is now empty after deleting the only node." << std::endl;
        return false;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
    return true;
}

bool LinkedList::deleteDataAtPosition(int position)
{
    if (!head)
    {
        std::cout << "List is empty." << std::endl;
        return false;
    }

    if (position < 1)
    {
        std::cout << "Position should be >= 1." << std::endl;
        return false;
    }

    if (position == 1)
    {
        bool result = deleteFromBeginning();
        if(result)
            return true;
        else
            return false;
    }

    Node *temp = head;
    for (int i = 1; i < position - 1 && temp; ++i)
    {
        temp = temp->next;
    }

    if (!temp || !temp->next)
    {
        std::cout << "Position out of range." << std::endl;

        return false;
    }
    Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
    return true;
}

bool LinkedList::deleteByValue(int value)
{

    if (!head)
    {
        std::cout << "List is empty." << std::endl;
        return false;
    }
    Node *temp = head;
    Node *prev = nullptr;

    if (temp && temp->data == value)
    {
        head = temp->next;
        delete temp;
        return true;
    }

    while (temp && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (!temp)
    {
        std::cout << "Not found.." << std::endl;
        return false;
    }

    prev->next = temp->next;
    delete temp;
    return true;
}

int LinkedList::searchElement(int value)
{
    if (!head)
    {
        std::cout << "List is empty." << std::endl;
        return -1;
    }

    int position = 0;
    Node *temp = head;
    while (temp)
    {
        position++;
        if (temp->data == value)
        {
            std::cout << "Found value at " << position << " position.." << std::endl;
            return position;
        }
        else
        {
            temp = temp->next;
        }
    }
    std::cout << "Not found.." << std::endl;
    return -1;
}

void LinkedList::reverseList()
{
    if (!head)
    {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;
    
    while(current!= nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    std::cout<<"List is reversed ...\n" ;
    return;
}

bool LinkedList::detectLoopUsingHashMap()
{
    std::cout<< "Checking loop using hash map .." <<std::endl;
    if (!head)
    {
        std::cout << "List is empty." << std::endl;
        return false;
    }

    std::unordered_set<Node*>map;

    Node *temp = head;

    while (temp != nullptr)
    {
        if(map.find(temp) != map.end()){
            return true;
        }

        map.insert(temp);

        temp = temp->next;
    }
    

    return false;
}

bool LinkedList::detectLoopUsingFloydAlgo()
{
    if (!head)
    {
        std::cout << "List is empty." << std::endl;
        return false;
    }

    Node *slow = head, *fast = head;

    while(slow != nullptr && fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }

    return false;
}
