#include "Queue.h"
#include <iostream>

void performAction(int option, Queue *queue)
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
            
            queue->enQueue(value);
             
            value = 0;
        }
        // system("clear");
        break;
    }

    case 2:
    {
        try
        {
            bool result = queue->deQueue();
            if (result)
                std::cout << "Removed successfully!!!" << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Failed due to --> " << e.what() << std::endl;
        }
        break;
    }
    case 3:
    {
        try
        {
            int result = queue->peek();
            std::cout << "Found front : " << result << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Failed due to --> " << e.what() << std::endl;
        }
        break;
    }
    case 4:
    {
        try
        {
            queue->displayQueue();
        }
        catch (const std::exception &e)
        {
            std::cout << "Failed due to --> " << e.what() << std::endl;
        }
        break;
    }
    case 5:
    {
        try
        {
            int result = queue->size();
            std::cout << "Size of queue : " << result << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Failed due to --> " << e.what() << std::endl;
        }
        break;
    }
    case 6:
    {
        if(queue->clear())
            std::cout<<"Queue cleared successfully!!"<<std::endl;
        else
            std::cout << "Queue is empty so no need to clear\n";
        
        break;
    }
    case 7:
        exit(0);
        break;

    default:
        std::cout << "Invalid choice!" << std::endl;
        break;
    }
    return;
}

int main()
{
    Queue *q = new Queue();
    while (true)
    {
        int option = 0;
        int value = 0;
        std::cout << "\n\n\n<<<... Program to perform Queue operation ...>>>" << std::endl;
        std::cout << "1. Enqueue" << std::endl;
        std::cout << "2. Dequeue" << std::endl;
        std::cout << "3. Peek" << std::endl;
        std::cout << "4. Print Queue" << std::endl;
        std::cout << "5. Size" << std::endl;
        std::cout << "6. Clear" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter the option : ";
        std::cin >> option;

        std::cout << "\n\n\n";
        performAction(option, q);
    }

    return 0;
}
