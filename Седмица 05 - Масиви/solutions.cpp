#include <algorithm>
#include <cstddef>
#include <iostream>

void print(int arr[], std::size_t n) {
  for (std::size_t i = 0; i < n; i++) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}

int sum(const int arr[], std::size_t size) {
  int result{};

  for (std::size_t i = 0; i < size; ++i) {
    result += arr[i];
  }

  return result;
}

int find_max(const int arr[], std::size_t size) {
  int max{arr[0]};

  for (std::size_t i = 1; i < size; ++i) {
    max = std::max(max, arr[i]);
  }

  return max;
}

std::size_t count_occurences(const int arr[], std::size_t size, int element) {
  std::size_t occurences{};

  for (std::size_t i = 0; i < size; ++i) {
    if (arr[i] == element) {
      ++occurences;
    }
  }

  return occurences;
}

int most_common(const int arr[], std::size_t size) {
  int max_element{arr[0]};
  std::size_t max_occurences{count_occurences(arr, size, max_element)};

  for (std::size_t i = 1; i < size; ++i) {
    std::size_t occurences = count_occurences(arr, size, arr[i]);
    if (max_occurences < occurences) {
      max_element = arr[i];
      max_occurences = occurences;
    }
  }

  return max_element;
}

std::size_t find_min_element_index(int arr[], std::size_t start,
                                   std::size_t size) {
  int min_element{arr[start]};
  std::size_t min_index{start};

  for (std::size_t i = start + 1; i < size; ++i) {
    if (min_element > arr[i]) {
      min_element = arr[i];
      min_index = i;
    }
  }

  return min_index;
}

void selection_sort(int arr[], std::size_t size) {
  for (std::size_t i = 0; i < size - 1; ++i) {
    std::size_t min_index = find_min_element_index(arr, i, size);
    std::swap(arr[i], arr[min_index]);
  }
}

int main() {
  int arr[]{10, 5, 8, 3, 13, 7};
  selection_sort(arr, 6);
  print(arr, 6); // -> 3 5 7 8 10 13
  return 0;
}