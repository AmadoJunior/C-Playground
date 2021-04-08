#include <iostream>
#include <string>
#include <sstream>
#include <utility>

std::string compressString(std::string);
std::string compressStringImproved(std::string);

int main(){
    std::string s = "aaabccccaaa";
    std::cout << compressStringImproved(s) << std::endl;
    return 0;
}

std::string compressString(std::string s){
    //O(N) Time
    //O(N) SStream Grows with N
    std::pair<char, short> repetitions(s[0], 0);
    std::stringstream ss;
    ss << s[0];
    for(int i = 0; i < s.length(); i++){
        if(s[i] == repetitions.first){
            repetitions.second++;
        } else {
            ss << (short) repetitions.second;
            ss << s[i];
            repetitions.first = s[i];
            repetitions.second = 1;
        }
    }
    ss << (short) repetitions.second;
    return ss.str();
}

std::string compressStringImproved(std::string s){
    //O(N) Time
    //O(N) SStream Grows with N
    short count = 0;
    std::stringstream ss;
    for(int i = 0; i < s.length(); i++){
        count++;
        if(i+1 >= s.length() || s[i] != s[i+1]){
            ss << s[i];
            ss << count;
            count = 0;
        }
    }
    return ss.str();
}