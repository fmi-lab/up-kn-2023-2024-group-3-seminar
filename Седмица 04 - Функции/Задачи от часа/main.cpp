#include <iostream>
#include <cmath>
#include <limits>

unsigned toBinary(unsigned n)
{
    unsigned result = 0;
    unsigned multiplier = 1;

    while (n != 0)
    {
        unsigned remainder = n % 2;

        result += remainder * multiplier;

        multiplier *= 10;
        n /= 2;
    }

    return result;
}

unsigned toPowerOf3(unsigned n)
{
    return n * n * n;
}

void cubes(unsigned n)
{
    unsigned i = 1;
    unsigned current = toPowerOf3(i);

    while (current < n)
    {
        std::cout << current << ' ';
        ++i;
        current = toPowerOf3(i);
    }
}

void sequence(unsigned n)
{
    for (size_t i = 1; i <= n; i++)
    {
        unsigned member = 2 * toPowerOf3(i) + 3 * i;
        std::cout << member << ' ';
    }
}

bool isPrime(unsigned n)
{
    unsigned curr = 2;
    while (curr <= sqrt(n) && n % curr != 0)
    {
        ++curr;
    }

    return curr > sqrt(n);
}

void primes(unsigned n)
{
    unsigned counter = 0;
    unsigned i = 2;

    while (counter < n)
    {
        if (isPrime(i))
        {
            std::cout << i << ' ';
            ++counter;
        }

        ++i;
    }
}

unsigned factorial(unsigned n)
{
    unsigned result = 1;

    for (size_t i = 1; i <= n; i++)
    {
        result *= i;
    }

    return result;
}

// n-choose-k
unsigned combinations(unsigned n, unsigned k)
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}

bool isMagic(unsigned n)
{
    unsigned sum = 0;

    for (size_t i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }

    return sum == n;
}

unsigned sumOfDigits(unsigned n) {
    unsigned sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

unsigned biggestDigitSum(unsigned n) {
    unsigned max = std::numeric_limits<unsigned>::min();
    unsigned max_number = 0;
    for (size_t i = 0; i < n; i++)
    {
        unsigned number;
        std::cin>>number;
        if(max <= sumOfDigits(number)) {
            max = sumOfDigits(number);
            max_number = number;
        }
    }
    return max_number;
}

bool isSumOfDigitsPrime(unsigned n) {
    return isPrime(sumOfDigits(n));
}

bool difference3(unsigned n) {
    unsigned max = 0;
    unsigned min = std::numeric_limits<unsigned>::max();

    while(n > 0) {
        unsigned lastDigit = n % 10;

        max = std::max(max, lastDigit);
        min = std::min(min, lastDigit);

        n /= 10;
    }

    return max - min == 3;
}

void printSatisfyingPredicates(unsigned n) {
    size_t counter = 0;
    unsigned current = 14;
    while(counter < n) {
        if(difference3(current) && isSumOfDigitsPrime(current)) {
            std::cout<<current << ' ';
            ++counter;
        }
        ++current;
    }
}

int main()
{
    printSatisfyingPredicates(7); // -> 14 25 30 41 47 52 58
    return 0;
}