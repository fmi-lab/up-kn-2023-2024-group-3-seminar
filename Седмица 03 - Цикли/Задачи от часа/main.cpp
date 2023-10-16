#include <iostream>

int main()
{
    for (int i = 0; i <= 10; ++i)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    unsigned n;
    std::cin >> n;

    unsigned res = 0;
    while (n != 0)
    {
        res *= 10;
        res += n % 10;

        n /= 10;
    }

    std::cout << '\n'
              << res << '\n';

    int n;
    do
    {
        std::cin >> n;
    } while (n < 10 || n > 99);

    

    return 0;
}