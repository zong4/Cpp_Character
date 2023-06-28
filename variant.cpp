// variant

#include <variant>
#include <string>
#include <iostream>

int main()
{
    std::variant<int, std::string> var = 1;
    
    // std::cout<<var<<std::endl; // error, can't cout << variant
    // std::cout<<std::get<1>(var)<<std::endl // error, string is not initialize

    var = "123";
    std::cout<<std::get<0>(var)<<std::endl; // error, int is delete
    std::cout<<std::get<1>(var)<<std::endl; 

    var = std::variant<int, std::string>("123"); 
    // std::cout<<std::get<1>(var)<<std::endl; 

    return 0;
}