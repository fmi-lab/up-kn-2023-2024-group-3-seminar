#include <algorithm>
#include <cstddef>
#include <iostream>

int sum_interval(int a, int b) {
  if (b == a) {
    return a;
  }

  return b + sum_interval(a, b - 1);
}

unsigned count_digits(unsigned n) {
  if (n == 0) {
    return 0;
  }

  return 1 + count_digits(n / 10);
}

unsigned gcd_rec(unsigned a, unsigned b) {
  if (a == 0) {
    return b;
  }

  return gcd_rec(b % a, a);
}

double quick_pow(double x, int n) {
  if (n == 0) {
    return 1;
  }

  if (n < 0) {
    return 1 / quick_pow(x, -n);
  }

  if (n % 2) {
    return x * quick_pow(x, n - 1);
  } else {
    return quick_pow(x * x, n / 2);
  }
}

void print_reverse(const char str[], int begin) {
  if (!str[begin]) {
    return;
  }

  print_reverse(str, begin + 1);
  std::cout << str[begin];
}

int find_first_even(const int arr[], std::size_t begin, std::size_t end) {
  if (begin == end) {
    return -1;
  }

  if (arr[begin] % 2 == 0) {
    return begin;
  }

  return find_first_even(arr, begin + 1, end);
}

bool is_palindrome(const int arr[], std::size_t begin, std::size_t end) {
  if(begin >= end - 1) {
    return true;
  }
  
  if(arr[begin] != arr[end - 1]) {
    return false;
  }

  return is_palindrome(arr, begin + 1, end -1);
}

int max_repeated_helper(const int arr[],
                        std::size_t begin, 
                        std::size_t end,
                        std::size_t count,
                        std::size_t max_count,
                        int element) {
  if(begin == end) {
    return std::max(count, max_count);
  }

  if(arr[begin] != element) {
    return max_repeated_helper(arr, begin + 1, end, 1, std::max(count, max_count), arr[begin]);
  }

  return max_repeated_helper(arr, begin + 1, end, count + 1, max_count, element);
}

int max_repeated(const int arr[], std::size_t begin, std::size_t end) {
  return max_repeated_helper(arr, begin + 1, end, 1, 0, arr[begin]);
}

int main() {
  const int arr[] {1, 1, 2, 3, 3, 3, 4, 2, 2, 2, 2};
std::cout << max_repeated(arr, 0, 11); // -> 4
  return 0;
}