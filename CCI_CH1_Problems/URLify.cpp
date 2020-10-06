#include <string>
#include <sstream>
#include <iostream>

std::string URLify1(std::string, int);
std::string URLify2(std::string, int);

int main(){
    std::string s = "Mr John Smith Hello      ";
    int length = 19;
    std::cout << URLify2(s, length) << std::endl;
    return 0;
}

std::string URLify1(std::string s, int actualLength){
    //O(actualLength) Time
    //O(s.length) Space
    std::stringstream ss;
    for(int i = 0; i < actualLength; i++){
        if(s[i] == ' '){
            ss << "%20";
        } else {
            ss << s[i];
        }
    }
    return ss.str();
}

std::string URLify2(std::string s, int length){
    //O(s.length) Time
    //O(1) Space
    for(int i = s.length()-1; i > 0; i--){
        length--;
        if(s[length] == ' '){
            s[i] = '0';
            i--;
            s[i] = '2';
            i--;
            s[i] = '%';
        } else {
            s[i] = s[length];
        }
    }
    return s;
}