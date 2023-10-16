#include <iostream>
#include <cmath>

int main() {
    unsigned n;
    std::cin >> n;

    unsigned i = 2;
    while(i < sqrt(n) && n % i != 0) {
        ++i;
    }

    std::cout<<std::boolalpha<<(i >= sqrt(n))<<'\n';
    return 0;
}