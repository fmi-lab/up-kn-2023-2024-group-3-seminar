#include <iostream>
#include <cmath>

int main() {
    double a,b;

    std::cin>>a>>b;

    double epsilon = 0.00001;

    std::cout<<std::boolalpha<<(fabs(a - b) < epsilon)<<'\n';

    return 0;
}