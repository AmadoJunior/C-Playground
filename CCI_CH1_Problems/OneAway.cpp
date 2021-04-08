#include <iostream>
#include <string>
#include <cmath>

bool isOneAway(std::string, std::string);

int main(){
    std::string s1 = "qqle";
    std::string s2 = "dqle";
    bool isit = isOneAway(s1, s2);
    std::cout << isit << std::endl;
    return 0;
}

bool isOneAway(std::string s1, std::string s2){
    //O(N) Time
    //O(1) Space

    //Get Shorter && Longer String
    bool misMatchChar = false;
    std::string first = s1.length() < s2.length() ? s1 : s2;
    std::string second = s1.length() < s2.length() ? s2 : s1;

    //Length Check
    if(std::abs(second.length() - first.length()) > 1){
        std::cout << "String too long" << std::endl;
        return false;
    }

    if(s1.length() == s2.length()){
        for(int i = 0; i < s1.length(); i++){
            if(s1[i] != s2[i]){
                if(!misMatchChar){
                    misMatchChar = true;
                } else {
                    return false;
                }
            }
        }
        return true;
    } else {
        int i = 0;
        int j = 0;
        while(i < first.length() && j < second.length()){
            if(first[i] != second[j] && !misMatchChar){
                misMatchChar = true;
                j++;
            } else if(first[i] != second[j] && misMatchChar) {
                return false;
            } else {
                i++;
                j++;
            }
        }
        return true;
    }
}