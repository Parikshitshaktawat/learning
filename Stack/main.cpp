#include "Stack.h"
#include <iostream>

void performAction(int option, Stack *stack)
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
            try
            {
                bool result = stack->push(value);
                if (result)
                    std::cout << "Pushed successfully!!!" << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cout << "Failed due to --> " << e.what() << std::endl;
            }
            value = 0;
        }
        // system("clear");
    }

    break;
    case 2:
    {
        try
        {
            bool result = stack->pop();
            if (result)
                std::cout << "Poped successfully!!!" << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Failed due to --> " << e.what() << std::endl;
        }
    }
    break;
    case 3:
    {
        try
        {
            int result = stack->peak();
            std::cout << "Found top : " << result << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Failed due to --> " << e.what() << std::endl;
        }
    }
    break;
    case 4:
    {
        try
        {
            stack->traverse();
        }
        catch (const std::exception &e)
        {
            std::cout << "Failed due to --> " << e.what() << std::endl;
        }
    }
    break;
    case 5:
    {
        int result = stack->size();
        try
        {
            int result = stack->size();
            std::cout << "Size of stack : " << result << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Failed due to --> " << e.what() << std::endl;
        }
    }
    break;
    case 6:
    {
        try
        {
            bool result = stack->clear();
            if (result)
                std::cout << "Cleared successfully!!!" << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Failed due to --> " << e.what() << std::endl;
        }
    }
    break;
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
    Stack top;
    while (true)
    {
        int option = 0;
        int value = 0;
        std::cout << "\n\n\n<<<... Program to perform stack operation ...>>>" << std::endl;
        std::cout << "<<<... Stack Operations ...>>>" << std::endl;
        std::cout << "1. Push" << std::endl;
        std::cout << "2. Pop" << std::endl;
        std::cout << "3. Peek" << std::endl;
        std::cout << "4. Traverse" << std::endl;
        std::cout << "5. Size" << std::endl;
        std::cout << "6. Clear" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter the option : ";
        std::cin >> option;

        std::cout << "\n\n\n";
        performAction(option, &top);
    }

    return 0;
}
