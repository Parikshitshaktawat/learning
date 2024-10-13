#include <iostream>


/*
Recursion vs. Iteration:
Iteration is generally the better choice for the Fibonacci series because it avoids the overhead of recursive 
function calls and recalculations. It’s more efficient in both time and memory, making it the preferred choice for performance-critical applications.

Recursion is useful for problems like the Tower of Hanoi, tree traversal, or backtracking (as you mentioned), 
where breaking the problem down into subproblems simplifies the solution. But in the case of Fibonacci numbers, 
the recursive approach leads to exponential time complexity unless it's optimized with memoization or dynamic programming.

For calculating Fibonacci numbers, if performance and memory efficiency are important, the iterative approach would be the better choice. 
This is because the recursive version of Fibonacci has an exponential time complexity, and the iterative version runs in linear time 
while using constant memory.

*/


void fibboLoop(int input){
    int prev1 = 0;
    int prev2 = 1;

    std::cout << "Fibbonaci by loop: "<< prev1 << " " << prev2;
    for(int i = 1; i < (input -1); i++ ){
        int curr = prev1 + prev2;
        std::cout << " " << curr ;
        prev1 =  prev2;
        prev2 = curr;
    }  
}


int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int num;
    std::cout << "Enter the number of Fibonacci terms to print: ";
    std::cin >> num;
    
    fibboLoop(num);

    std::cout <<std::endl <<"Fibonacci Series : ";
    for (int i = 0; i < num; i++) {
        std::cout << fibonacci(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
