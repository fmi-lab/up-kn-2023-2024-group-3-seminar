#include <iostream>

int main() {
    int a,b,c;
    std::cin>>a>>b>>c;

    int max = a > b && a > c ? a :
              b > a && b > c ? b : c;

    int min = a < b && a < c ? a :
              b < a && b < c ? b : c;

    int mid = (a + b + c) - max - min;

    std::cout<<min<<' '<<mid<<' '<<max<<'\n';

    return 0;
}