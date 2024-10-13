#include<iostream>

// int main(){
// int input1 = 0, input2 = 0;
// std::cout<<"Enter the input 1 : " ;
// std::cin >> input1;
// std::cout<< std::endl <<"Enter the input 2 : " ;
// std::cin >> input2;
// if(input1 > input2){
// std::cout<<std::endl<<"Input 1 is larger";
// }
// else{
// std::cout<<std::endl<<"Input 2 is larger" << std::endl;
// }

// return 0;
// }

// int main(){
// for(int i =1 ; i <= 10; i++){
// std::cout<< i << ", ";
// }
// std::cout<<std::endl;
// return 0;
// }

// int multiply(int a, int b){
// return a*b;
// }
// int main(){
// int result = multiply(10,5);
// std::cout << result << std::endl;
// return 0;
// }

//Pass by reference example

int multiply(int &a, int &b){
    return a*b;
}

int main(){
    int n1 = 3, n2 = 4;
    int result = multiply(n1 , n2);

    std::cout<< "The result of multiplication is : "<<result <<std::endl;
    std::cout << "Orignal values are " << n1 << " and " << n2 << std::endl;
}


