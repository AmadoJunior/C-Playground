#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, std::string>  genreRating;
    genreRating["Horror"] = "Ehh";
    genreRating["Romance"] = "Awful";
    genreRating["Action"] = "Bad";
    genreRating["Comedy"] = "Yes";
    genreRating["Sci fi"] = "Cheesy";
    std::cout << genreRating["Comedy"] << std::endl;
    return 0;
}
