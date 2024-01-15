#include <algorithm>
#include <cstddef>
#include <cstring>
#include <ios>
#include <iostream>
#include <cmath>

struct UnsignedArray {
  unsigned* data;
  std::size_t size;
};

bool are_equal(double a, double b) {
  constexpr double EPSILON = 0.000001;  //1e-6;

  return std::fabs(a - b) < EPSILON;
}

void find_max_equal_distance(double arr[], std::size_t size) {
  for(int k = size - 2; k >= 1; --k) {
    int i = 0;
    double diff = std::fabs(arr[k] - arr[0]);

    while (i + k < size && are_equal(std::fabs(arr[i] - arr[i+k]), diff)) {
      ++i;
    }

    if(i + k == size) {
      std::cout<<k<<'\n';
      return;
    }
  }

  std::cout<<"No solution\n";
}

char* find_min(char* str) {
  char* min = str;

  while (*str) {
    if(*str < *min) {
      min = str;
    }
    ++str;
  }

  return min;
}

void sort(char* str) {
  while (*str) {
    char* min = find_min(str);

    std::iter_swap(str, min);

    ++str;
  }
}

bool are_anagrams(char* lhs, char* rhs) {
  sort(lhs);
  sort(rhs);

  return strcmp(lhs, rhs) == 0;
}

unsigned count_digits(int n) {
  unsigned count = 0;

  while (n) {
    ++count;
    n /= 10;
  }

  return count;
}

unsigned count_ones_in_binary(int n) {
  unsigned count = 0;

  while(n) {
    count += n % 2;
    n /= 2;
  }

  return count;
}

void push_back(UnsignedArray& arr, unsigned n) {
  unsigned *newData = new unsigned[arr.size + 1];
  for (std::size_t i = 0; i < arr.size; ++i) {
    newData[i] = arr.data[i];
  }
  newData[arr.size] = n;

  delete [] arr.data;
  arr.data = newData;
  ++arr.size;
}

UnsignedArray filter(const UnsignedArray& arr) {
  UnsignedArray result = {.data = nullptr, .size = 0};

  for (std::size_t i = 0; i < arr.size; ++i) {
    if(count_digits(arr.data[i]) < count_ones_in_binary(arr.data[i])) {
      push_back(result, arr.data[i]);
    }
  }

  return result;
}

unsigned gcd(unsigned a, unsigned b) {
  if(a > b) {
    return gcd(b, a);
  }

  if(a == 0) {
    return 0;
  }

  if(b % a == 0) {
    return a;
  }

  return gcd(a, b % a);
}

unsigned find_neighbours_helper(const unsigned matrix[][255], int rows, int cols, unsigned k, int x, int y, unsigned prev, bool** visited) {
  if(x < 0 || x >= rows || y < 0 || y >= cols || visited[x][y] || gcd(matrix[x][y], k) != prev) {
    return 0;
  }

  visited[x][y] = true;
  unsigned count = 1;

  count += find_neighbours_helper(matrix, rows, cols, k, x + 1, y, prev, visited);
  count += find_neighbours_helper(matrix, rows, cols, k, x - 1, y, prev, visited);
  count += find_neighbours_helper(matrix, rows, cols, k, x, y + 1, prev, visited);
  count += find_neighbours_helper(matrix, rows, cols, k, x, y - 1, prev, visited);

  return count;
}

unsigned find_neighbours(const unsigned matrix[][255], int rows, int cols, unsigned k) {
  bool** visited = new bool*[rows];
  for (int i = 0; i < rows; ++i) {
    visited[i] = new bool[cols]{};
  }

  unsigned count = 0;

  for(int i = 0; i < rows; ++i) {
    for(int j = 0; j < cols; ++j) {
      count = std::max(count, find_neighbours_helper(matrix, rows, cols, k, i, j, gcd(matrix[i][j], k), visited));
    }
  }

  for(int i = 0; i < rows; ++i) {
    delete [] visited[i];
  }
  delete[] visited;

  return count;
}

int main() {
  unsigned *data = new unsigned[7]{2, 7, 16, 34, 19, 336, 21};

  UnsignedArray arr = {.data = data, .size = 7};

  UnsignedArray result = filter(arr);

  for(std::size_t i = 0; i < result.size; ++i) {
    std::cout<<result.data[i]<<' ';
  }
  std::cout<<'\n';

  delete [] data;
  return 0;
}