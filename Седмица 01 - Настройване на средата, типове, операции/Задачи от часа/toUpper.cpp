#include <iostream>

int main() {
    char c;
    std::cin >> c;

    std::cout<<(char)(c - ('a' - 'A'))<<'\n';

    return 0;
}