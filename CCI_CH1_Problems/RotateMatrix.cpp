#include <iostream>

void rotateMatrix(int[][4]);

int main(){
    int myArr[][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    rotateMatrix(myArr);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            std::cout << myArr[i][j] << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}

void rotateMatrix(int matrix[][4]){
    //O(N^2) Time
    //O(1) Space
    //Arr Size
    int size = 4;
    //Iterate Through the Layers
    for(int layer = 0; layer < size/2; layer++){
        //Find First Index and Last Index in Current Layer
        int first = layer;
        int last = size - 1 - layer;
        //Iterating and Swapping
        for(int i = first; i < last; i++){
            //Offset - Apply to numbers that move in a negative direction
            int offset = i - first;
            //Saving Top Value
            int top = matrix[first][i];
            //Left -> Top
            matrix[first][i] = matrix[last-offset][first];
            //Bottom -> Left
            matrix[last-offset][first] = matrix[last][last-offset];
            //Right -> Bottom
            matrix[last][last-offset] = matrix[i][last];
            //Top -> Right
            matrix[i][last] = top;
        }
    }
}