#include <iostream>
#include <regex>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){
    string pattern("[^c]ei");
    pattern="[[:alpha:]]*"+pattern+"[[:alpha:]]*";
    std::regex r(pattern);
    std::smatch results;
    string test_str="receipt freind theif receive";
    if(std::regex_search(test_str, results, r))
        cout << results.str()<< endl;
    return 0;
}
