#include <cstddef>
#include <iostream>

bool isLetter(char c) { return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'; }

bool isDigit(char c) { return c >= '0' && c <= '9'; }

unsigned short toDigit(char c) { return c - '0'; }

void to_upper_case(char str[]) {
  std::size_t i = 0;
  while (str[i]) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] -= 'a' - 'A';
    }

    ++i;
  }
}

int atoi(const char str[]) {
  bool isNegative = str[0] == '-';
  std::size_t i = isNegative ? 1 : 0;
  int result = 0;

  while (isDigit(str[i])) {
    result = result * 10 + toDigit(str[i]);
    ++i;
  }

  return isNegative ? -result : result;
}

std::size_t find_longest_word(const char str[]) {
  std::size_t max_length = 0;
  std::size_t curr_length = 0;
  std::size_t max_index = 0;
  std::size_t i = 0;

  while (str[i]) {
    if (!isLetter(str[i])) {
      if (curr_length > max_length) {
        max_length = curr_length;
        max_index = i - curr_length;
      }

      curr_length = 0;
    } else {
      ++curr_length;
    }

    ++i;
  }

  if (curr_length > max_length) {
    max_length = curr_length;
    max_index = i - curr_length;
  }

  return max_index;
}

void decode(char destination[], const char source[]) {
  std::size_t destination_index = 0;
  std::size_t source_index = 0;
  unsigned count = 0;

  while (source[source_index]) {
    if (isDigit(source[source_index])) {
      count = count * 10 + toDigit(source[source_index]);
    } else {
      for (std::size_t i = 0; i < (!count ? 1 : count); ++i) {
        destination[destination_index++] = source[source_index];
      }
      
      count = 0;
    }

    ++source_index;
  }

  destination[destination_index] = '\0';
}

int find_word(const char str[], const char word[]) {
  std::size_t i = 0;

  while (str[i]) {
    if(isLetter(str[i])) {
      std::size_t j = 0;
      std::size_t curr = i;
      while (word[j] && isLetter(str[curr]) && word[j] == str[curr]) {
        ++j;
        ++curr;
      }

      if(!word[j] && !isLetter(str[curr])) {
        return i;
      }

      if(!isLetter(str[i])) {
        i = curr;
      }

      if(!word[j]) {
        while (isLetter(str[curr])) {
          ++curr;
        }

        i = curr;
      }
    }

    ++i;
  }

  return -1;
}

int main() {
  std::cout<<find_word("I am the best programmer ever", "programmer"); // -> 14

  return 0;
}