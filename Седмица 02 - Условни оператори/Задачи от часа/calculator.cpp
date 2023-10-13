#include <iostream>

int main() {
    double a, b;
    char c;

    std::cin>>a>>c>>b;

    switch (c)
    {
    case '+':
        std::cout<<a+b<<'\n';
        break;
    case '-':
        std::cout<<a-b<<'\n';
        break;
    case '*':
        std::cout<<a*b<<'\n';
        break;
    case '/':
        std::cout<<a/b<<'\n';
        break;
    default:
        std::cout<<"Invalid operation\n";
        break;
    }

    return 0;
}