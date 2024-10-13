#include <iostream>

void updateValue(int *p){

    *p = *p * 2;
}

void printValues(int *arr , int size){

    for(int i = 0 ; i < size; i++){
        std::cout << "Value at " << i+1 << " position is : "  << arr[i] << std::endl;
    }
}

void initilizeValues(int *arr , int size){

    for(int i = 0 ; i < size; i++){
        arr[i] = rand() % 5 + 1;
    }
    std::cout << "Value Updated..." << std::endl;
}


int main(){
    int num1 = 1;
    int *ptr = &num1;
    const int size = 5;
    int *arr = new int[size]();
    updateValue(ptr);
    std::cout << "Value at the memory location : " << *ptr << std::endl;
    initilizeValues(arr, size);
    printValues(arr, size);
    delete arr;
    return 0;


}

