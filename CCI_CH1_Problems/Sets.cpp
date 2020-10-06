#include <iostream>
#include <unordered_set>

int main(){
    const int N = 5;
    int arr[N] = {1,2,3,4,4};
    std::unordered_set<int> mySet(arr, arr+N);
    for(int i : mySet){
        std::cout << i << std::endl;
    }
    return 0;
}
