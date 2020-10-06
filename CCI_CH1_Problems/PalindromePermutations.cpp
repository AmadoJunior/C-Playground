#include <iostream>
#include <string>
#include <sstream>
#include <map>

bool isPalindromePermutation(std::string);

int main(){
    std::string s = "tact coa ";
    std::cout << isPalindromePermutation(s) << std::endl;
    return 0;
}

bool isPalindromePermutation(std::string s){
    //O(N) Time
    //O(N) Space 
    int countNonSpace = 0;
    std::map<char, int> uniqueChars;
    for(char c : s){
        if(c == ' '){
            continue;
        } else {
            if(!uniqueChars.count(c)){
                uniqueChars[c] = 1;
            } else {
                uniqueChars.erase(c);
            }
            countNonSpace++;
        }
    }
    if(uniqueChars.size() == 1){
        return true;
    } else {
        return false;
    }
}