#include <algorithm>
#include <iostream>

void print(const int *begin, const int *end) {
  while (begin != end) {
    std::cout << *begin++ << ' ';
  }
  std::cout << '\n';
}

const int *upper_bound(const int *begin, const int *end, int element) {
  while (begin != end) {
    const int *mid = begin + (end - begin) / 2;

    if (*mid <= element) {
      begin = mid + 1;
    } else {
      end = mid;
    }
  }

  return *begin > element ? begin : nullptr;
}

bool equal(const int *first_begin, const int *first_end,
           const int *second_begin, const int *second_end) {
  while (first_begin != first_end && second_begin != second_end &&
         *first_begin == *second_begin) {
    ++first_begin;
    ++second_begin;
  }

  return first_begin == first_end && second_begin == second_end;
}

void reverse(int *begin, int *end) {
  while (begin < end - 1) {
    std::iter_swap(begin, end - 1);
    ++begin;
    --end;
  }
}

void rotate(int *begin, int *mid, int *end) {
  reverse(begin, mid);
  reverse(mid, end);
  reverse(begin, end);
}

const int *search(const int *first_begin, const int *first_end,
                  const int *second_begin, const int *second_end) {
  while (first_begin != first_end - (second_end - second_begin)) {
    if (equal(first_begin, first_begin + (second_end - second_begin),
              second_begin, second_end)) {
      return first_begin;
    }

    ++first_begin;
  }

  return nullptr;
}

const int *partition(int *begin, int *end, int element) {
  while (begin != end) {
    if(*begin > element) {
      rotate(begin, begin + 1, end--); // С rotate запазваме относителната наредба на елементите
    } else {
      ++begin;
    }
  }

  return begin;
}

int main() {
  int arr[]{4, 7, 1, 3, 2, 6, 5, 9, 0};
  const int *mid = partition(std::begin(arr), std::end(arr), 5);

  print(std::begin(arr), mid); // -> 4 0 1 3 2
  print(mid, std::cend(arr));  // -> 5 9 6 7
  return 0;
}