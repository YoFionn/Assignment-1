#include <iostream>
#include <array>

void swap(int *x, int *y){
    int s = *x;
    *x = *y;
    *y = s;
}

void printArray(int printedArr[]){
    for(int i = 0; i < sizeof(printedArr); ++i){
        std::cout<<printedArr[i]<<", "<<std::endl;
    }
}

int partition(int a[], int p, int r){
    int x = a[r];
    int i = p-1;
    for(int j = p; j < r; ++j){
        if(a[j] <= x){
            i = i + 1;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i + 1], &a[r]);
    return i+1;
}

void quicksort(int a[],int p,int r){
    while(p<r){
        int q = partition(a,p,q-1);
        quicksort(a,p,r);
        quicksort(a,q+1,r);
    }
}

int main(){
    int n;
    int a[n];
    std::cout<<"Type in the size of your array"<<std::endl;
    std::cin>>n;
    std::cout<<"Type in numbers that you want in your array and I’ll sort them for you"<<std::endl;
    for(int j = 0; j < n; ++j){
    std::cin>>a[j];    
    }
    
    quicksort(a, 0, sizeof(a));
    std::cout<<"Your array sorted by quicksort is: \n"<<std::endl;
    printArray(a);
    return 0;
}

