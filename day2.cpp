#include <iostream>
#include <string>

int sum(int *arr, int size){
    int total = 0;
    for (int i = 0; i < size; i++){
        total = total + arr[i];
    }
    return total;
}

int count_vowels(std::string arr){
    int count = 0;
    for(int i = 0; i < arr.length(); i++){
        if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u' || arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U' )
        count ++;
    }
    return count;
}

int main(){
    int arr[] = {1,2,3,5,4,6,9,7,8,10};
    std::string str = "HelloChatGptHowAreYou";
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = sum(&arr[0] , size);
    int count = count_vowels(str);
    std::cout<< "Vowels count : " <<count <<std::endl;
    std::cout<< "Result is : " <<result <<std::endl;
}
