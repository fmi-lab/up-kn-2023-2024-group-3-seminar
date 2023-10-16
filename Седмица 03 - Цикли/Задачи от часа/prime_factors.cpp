#include <iostream>

int main() {
    int a = 1, b = 1;
    // std::cout<<++a<<' '<<b++<<'\n';
    // std::cout<<a<<' '<<b<<'\n';
    
    unsigned n;
    std::cin>>n;

    int i = 2;
    while(n != 1) {
        if(n % i == 0) {
            std::cout<<i<<(n == i ? "" : " * ");
            n /= i;
        } else {
            ++i;
        }
    }
    std::cout<<'\n';

    return 0;
}