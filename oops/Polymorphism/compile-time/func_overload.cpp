/**
 * @file func_overload.cpp
 * @author Parikshit Shaktawat (parikshitshaktawat.it@gmail.com)
 * @brief Basic concept of function overloading is to use the same function name of multiple function and all function calls will be decided 
 * @brief while compiling the code means its decided on the compile time thats why its called compile time polymorphism
 * @version 0.1
 * @date 2024-10-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>

class Calculator
{
public:
    // Calculator();
    int add(int x, int y)
    {
        return x + y;
    }

    char *add(const char *str1, const char *str2)
    {
        int len1 = 0;
        while (str1[len1] != '\0')
        {
            len1++;
        }

        int len2 = 0;
        while (str2[len2] != '\0')
        {
            len2++;
        }

        char *result = new char[len1 + len2 + 1];

        for (int i = 0; i < len1; i++)
        {
            result[i] = str1[i];
        }

        for (int i = 0; i < len2; i++)
        {
            result[len1 + i] = str2[i];
        }

        result[len1 + len2] = '\0';

        return result;
    }

    double add(double x, double y){
        return x + y;
    }
};

int main(){
    Calculator *object = new Calculator();
    const char *str1 = "Hello";
    const char *str2 = " World!!";

    std::cout << "X and Y are integer : " << object->add(6, 9) << "\n" ; // Here /n is used besause using std::endl flushes the output which takes a little extra time 
    std::cout << "Passing two string : " << object->add(str1,str2) << "\n" ; // Here /n is used besause using std::endl flushes the output which takes a little extra time 
    std::cout << "X and Y are double : " << object->add(6.5, 3.9) << "\n" ; // Here /n is used besause using std::endl flushes the output which takes a little extra time 

}