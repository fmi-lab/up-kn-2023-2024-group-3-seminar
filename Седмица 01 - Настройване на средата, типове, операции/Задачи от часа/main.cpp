#include <iostream>

int main() {
    int a, b;
    std::cin>>a>>b;

    a += b;
    b = a - b;
    a -= b;

    std::cout<<a<<" "<<b<<"\n";

    return 0;
}