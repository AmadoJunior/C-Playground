#include <iostream>
#include <vector>
#include <map>

/**
 * WIP
 */

std::vector<std::string> possibleCombinations(std::string, std::vector<std::string>);
std::map<char, int> createKeyPad();

int main(){
    return 0;
}

std::map<char, int> createKeyPad(){
    std::map<char, int> keyPad;
    int count = 3;
    int num = 0;
    for(int i = 97; i < 123; i++){
        if(count%3 == 0){
            num++;
        }
        if(num == 7){
            keyPad.insert(std::pair<char, int>((char)i, num));
            keyPad.insert(std::pair<char, int>((char)i+1, num));
            i++;
        } else if(num == 9){
            keyPad.insert(std::pair<char, int>((char)i, num));
            keyPad.insert(std::pair<char, int>((char)i+1, num));
            i++;
        } else {
            keyPad.insert(std::pair<char, int>((char)i, num));
        } 
        count++;
    }
}

std::vector<std::string> possibleCombinations(std::string phoneNum, std::vector<std::string> words){
    std::map<char, int> keyPad = createKeyPad();

    for(std::string word : words){
        //String to Int
        int wordNum = 0;
        for(char c : word){
            
        }
        for(char numKey : phoneNum){

        }
    }
}
