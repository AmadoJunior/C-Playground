<<<<<<< HEAD
#include <iostream>
#include <map>

void zeroMatrix(int[][4], const int, const int);

int main(){
    int myArr[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {0,1,1,1},
        {1,1,1,1}
    };
    zeroMatrix(myArr, 4, 4);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            std::cout << myArr[i][j] << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}

void zeroMatrix(int matrix[][4], const int ROW, const int COL){
    std::map<int, bool> ignoreRow;
    std::map<int, bool> ignoreCol;
    for(int i = 0; i < ROW; i++){
        if(ignoreRow.count(i)){
            continue;
        }
        for(int j = 0; j < COL; j++){
            if(ignoreCol.count(j)){
                continue;
            }
            if(matrix[i][j] == 0){
                for(int f = 0; f < COL; f++){
                    matrix[i][f] = 0;
                }
                for(int g = 0; g < ROW; g++){
                    matrix[g][j] = 0;
                }
                ignoreRow[i] = true;
                ignoreCol[j] = true;
            }
        }
    }
=======
#include <iostream>
#include <map>

void zeroMatrix(int[4][4], const int, const int);

int main(){
    int myArr[4][4] = {
        {0,2,3,1},
        {1,6,1,1},
        {1,1,0,1},
        {1,1,1,1}

    };
    zeroMatrix(myArr, 4, 4);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            std::cout << myArr[i][j] << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}

void zeroMatrix(int matrix[4][4], const int ROW, const int COL){
    //O(ROW * COL) Time
    //O(ROW + COL) Space
    std::map<int, bool> ignoreRow;
    std::map<int, bool> ignoreCol;
    for(int i = 0; i < ROW; i++){
        if(ignoreRow[i]){
            continue;
        }
        for(int j = 0; j < COL; j++){
            if(ignoreCol[j]){
                continue;
            }
            if(matrix[i][j] == 0){
                for(int f = 0; f < COL; f++){
                    matrix[i][f] = 0;
                }
                for(int g = 0; g < ROW; g++){
                    matrix[g][j] = 0;
                }
                ignoreRow[i] = true;
                ignoreCol[j] = true;
                break;
            }
        }
    }
>>>>>>> 06643cfd12977568bd0ce44e4c271c7ea777e736
}