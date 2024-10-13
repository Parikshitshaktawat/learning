// main.cpp
#include "LinkedList.h"
#include <iostream>
#include <cstdlib>

void performAction(int option, LinkedList *list)
{
  switch (option)
  {
  case 1:
  {

    int value = 0;
    bool stop = false;
    while (!stop)
    {
      std::cout << "Enter value to insert and to end inserting press -1 : ";
      std::cin >> value;
      if (value == -1)
      {
        stop = true;
        break;
      }
      list->createNode(value);
      value = 0;
    }
    system("clear");
    list->printList();
  }

  break;
  case 2:
  {
    list->printList();
  }
  break;
  case 3:
  {
    int value = 0;
    std::cout << "Enter the value to search : ";
    std::cin >> value;
    list->searchElement(value);
  }
  break;
  case 4:
  {
    int value = 0;
    std::cout << "Enter the node position to delete: ";
    std::cin >> value;
    bool result = list->deleteDataAtPosition(value);
    if (result)
      std::cout << "Deleted successfully!!!" << std::endl;
    else
      std::cout << "Failed to delete" << std::endl;
  }
  break;
  case 5:
  {
    bool result = list->deleteFromBeginning();
    if (result)
      std::cout << "Deleted successfully!!!" << std::endl;
    else
      std::cout << "Failed to delete" << std::endl;
  }
  break;
  case 6:
  {
    int value = 0;
    std::cout << "Enter the value to delete : ";
    std::cin >> value;
    bool result = list->deleteByValue(value);
    if (result)
      std::cout << "Deleted successfully!!!" << std::endl;
    else
      std::cout << "Failed to delete" << std::endl;
  }
  break;
  case 7:
    list->reverseList();
    break;
  case 8:
  {
    bool result = list->detectLoopUsingHashMap();
    if (result)
      std::cout << std::endl
                << "####--Found loop--####";
    else
      std::cout << "####--Loop not found--####";

    std::cout << std::endl;
  }
  break;
  case 9:
  {

    bool result = list->detectLoopUsingFloydAlgo();
    if (result)
      std::cout << std::endl
                << "####--Found loop--####";
    else
      std::cout << "####--Loop not found--####";
    std::cout << std::endl;

    break;
  }

  default:
    std::cout << "Invalid choice!" << std::endl;
    break;
  }
  return;
}

int main()
{
  LinkedList head;
  while (true)
  {
    int option = 0;
    int value = 0;
    std::cout << "\n\n\n<<<... Program to perform linked list operation ...>>>" << std::endl;
    std::cout << "To insert data in list press 1 " << std::endl;
    std::cout << "To print list press 2 " << std::endl;
    std::cout << "To search data in list press 3 " << std::endl;
    std::cout << "To delete data by position in list press 4 " << std::endl;
    std::cout << "To delete starting node in list press 5 " << std::endl;
    std::cout << "To delete data by value in list press 6 " << std::endl;
    std::cout << "To reverse the linked list press 7 " << std::endl;
    std::cout << "To detect loop in linked list using hash map press 8 " << std::endl;
    std::cout << "To detect loop in linked list using floyd algo press 9 " << std::endl;
    std::cout << "Enter the option : ";
    std::cin >> option;

    std::cout<< "\n\n\n";
    performAction(option, &head);
  }

  return 0;
}
