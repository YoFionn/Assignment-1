#include <iostream>
#include <cmath>
#include <array>
#include <vector>

void print(int input[], int len){
    for (int i = 0; i < len; i++){
        std::cout << input[i] << " " ;
    }    
    std::cout << std::endl;
}

void countingsort(int input[], int len){           
    int output[len] = {0};
    int max = input[0];
    for (int i = 1; i < len; i++){          //first we need to check what the biggest element in our code is. so we that know
        if (input[i] > max){                //how long our storrage array must be.
            max = input[i];
        }
    }

    int storrage[max] = {0};
    std::cout << max << std::endl;
    print(output, len);
    print(storrage, max);

    for (int i = 0; i < len; i++){         //we add for any number in the place of the number
        storrage[input[i]]++;
    }
    print(storrage, max);

    for (int i = 1; i <= max; i++){         //now we add every element of it to the previous
        storrage[i] += storrage[i-1];
    }
    print(storrage, max);
    print(output, len);

    for (int i = len-1; i >= 0; i--){               //in the last step we start with the last element of our input, and
        output[storrage[input[i]]-1] = input[i];    //look which element stands on the position of the inputs value in the storrage.
        --storrage[input[i]];                       //now we put the input element at the place which is described by the element of the
    }                                               //storage array into the output array. repead until the output is full.
    print(output, len);

    for(int i = 0; i < len; i++){                   //gives the input the finished sorted array
        input[i] = output[i];
    }
}


int main(int argc, char const *argv[])
{
    int length;
    std::cout << "please type in how many numbers your want to sort: "<< std::endl;
    std::cin >> length;
    int array[length];

    std::cout << "please type in the numbers: "<< std::endl;
    for (int i = 0; i < length; i++){
        std::cin >> array[i];
    }

    print(array, length);
    countingsort(array, length);
    std::cout << std::endl;
    std::cout << "This is your sorted array: ";
    print(array, length);
    return 0;
}