#include <iostream>

int main()
{
    unsigned n;
    std::cin >> n;

    int chars = n % 2 == 0 ? n + 1 : n;
    for (int row = 0; row < n / 2 + 1; ++row)
    {
        for(int intervals = 0; intervals < n/2 - row; ++intervals) {
            std::cout<<' ';
        }

        for(int stars = 0; stars < chars - 2*(n/2 - row); ++stars) {
            std::cout<<"*";
        }

        std::cout<<'\n';
    }

    for(int intervals = 0; intervals < n/2; ++intervals) {
        std::cout<<' ';
    }

    std::cout<<"|\n";
    return 0;
}