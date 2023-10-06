#include <iostream>

int main() {
    int year;
    std::cin>>year;

    bool a = year % 100 == 0;
    bool b = year % 400 == 0;
    bool c = year % 4 == 0;

    std::cout<<std::boolalpha<<((a && b) || (c && !a))<<'\n'; // simplified: c && !a || b

    return 0;
}