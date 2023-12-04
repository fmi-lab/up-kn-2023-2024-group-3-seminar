#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <new>

int *merge(int *first_begin, int *first_end, int *second_begin,
           int *second_end) {
  int *result =
      new int[(first_end - first_begin) + (second_end - second_begin)];
  std::size_t index = 0;

  while (first_begin != first_end && second_begin != second_end) {
    if (*first_begin < *second_begin) {
      result[index++] = *first_begin++;
    } else {
      result[index++] = *second_begin++;
    }
  }

  while (first_begin != first_end) {
    result[index++] = *first_begin++;
  }

  while (second_begin != second_end) {
    result[index++] = *second_begin++;
  }

  return result;
}

void print(int *begin, int *end) {
  while (begin != end) {
    std::cout << *begin++ << ' ';
  }

  std::cout << '\n';
}

void resize(char *&str) {
  char *newStr = new char[strlen(str) + 1 + 1]{};
  strcpy(newStr, str);
  delete[] str;
  str = newStr;
}

char *filter(char *str) {
  char *result = new char[1]{};
  std::size_t i = 0;

  while (*str) {
    if (*str != ' ') {
      resize(result);
      result[i++] = *str;
    }
    ++str;
  }

  return result;
}

int **allocate_matrix(std::size_t rows, std::size_t columns) {
  int **matrix = new (std::nothrow) int *[rows];
  for (std::size_t i = 0; i < rows; ++i) {
    matrix[i] = new int[columns];
  }
  return matrix;
}

void deallocate_matrix(int **matrix, std::size_t rows) {
  for (std::size_t i = 0; i < rows; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

void copy_matrix(int **dest, int **src, std::size_t rows, std::size_t columns) {
  for (std::size_t i = 0; i < rows; ++i) {
    for (std::size_t j = 0; j < columns; ++j) {
      dest[i][j] = src[i][j];
    }
  }
}

int **add_products(int **matrix, std::size_t rows, std::size_t columns) {
  int **result = allocate_matrix(rows + 1, columns);
  copy_matrix(result, matrix, rows, columns);
  std::fill(result[rows], result[rows] + columns, 1);

  for (std::size_t j = 0; j < columns; ++j) {
    for (std::size_t i = 0; i < rows; ++i) {
      result[rows][j] *= matrix[i][j];
    }
  }

  return result;
}

void print(int **matrix, std::size_t rows, std::size_t columns) {
  for (std::size_t i = 0; i < rows; ++i) {
    for (std::size_t j = 0; j < columns; ++j) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

int main() {
  std::size_t rows, columns;
  std::cin >> rows >> columns;

  int **matrix = allocate_matrix(rows, columns);

  for (std::size_t i = 0; i < rows; ++i) {
    for (std::size_t j = 0; j < columns; ++j) {
      std::cin >> matrix[i][j];
    }
  }

  int **result = add_products(matrix, rows, columns);

  print(result, rows + 1, columns);

  deallocate_matrix(matrix, rows);
  deallocate_matrix(result, rows + 1);

  return 0;
}