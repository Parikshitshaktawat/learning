#include <iostream>
#include <chrono>

int main()
{
    int option = 0;
    std::cin >> option;

    const int range = 100000;

    std::chrono::time_point<std::chrono::system_clock> start, end;

    if (option)
    {
        start = std::chrono::system_clock::now();
        for (int i = 0; i <= range; i++)
        {
            std::cout << i << std::endl; // std::endl with flushing
        }
        std::cout << "Calculated using endl\n";
        end = std::chrono::system_clock::now();
    }
    else
    {
        start = std::chrono::system_clock::now();
        for (int i = 0; i <= range; i++)
        {
            std::cout << i << "\n" << std::flush; // '\n' with explicit flushing
        }
        std::cout << "Calculated using backslash\n";
        end = std::chrono::system_clock::now();
    }

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";
}


//Inout size 1000
//Calculated endl 
// elapsed time: 0.00230205s
//Calculated backslash 
// elapsed time: 0.0053638s
//difference between both 0.00306175

//Input size 10000
//Calculated using endl
// Elapsed time: 0.358373s
//Calculated using backslash
// Elapsed time: 0.271597s

//Input size 100000
//Calculated using endl
// Elapsed time: 3.49046s

//Calculated using backslash
// Elapsed time: 3.7983s

//Using std::flush
// Calculated using endl
// Elapsed time: 0.300102s

//Calculated using backslash
// Elapsed time: 0.398875s


//Testing compiler flags current -O3
//Calculated using endl
// Elapsed time: 0.424035s

//Calculated using backslash
// Elapsed time: 0.363488s

//Testing compiler flag current -O2
//Calculated using endl
// Elapsed time: 0.431027s

//Calculated using backslash
// Elapsed time: 0.38109s





