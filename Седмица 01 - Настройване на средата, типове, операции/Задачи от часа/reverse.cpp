#include <iostream>

int main() {
    int n;
    std::cin>>n;

    int b = n % 10;
    b *= 1000;
    n /= 10;
    b += (n % 10) * 100; 
    n /= 10;
    b += (n % 10) * 10;
    n /= 10;
    b += n % 10;

    std::cout<<b<<'\n';

    return 0;
}