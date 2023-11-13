#include <algorithm>
#include <cstddef>
#include <iostream>

constexpr std::size_t MAX_SIZE{255};

void print(const int matrix[][MAX_SIZE], std::size_t rows, std::size_t columns) {
  for (std::size_t i = 0; i < rows; ++i) {
    for (std::size_t j = 0; j < columns; ++j) {
      std::cout<<matrix[i][j]<<' ';
    }
    std::cout<<'\n';
  }
}

std::size_t min_element_array(const int arr[], int n) {
  int min = arr[0];

  for (std::size_t i = 1; i < n; ++i) {
    min = std::min(min, arr[i]);
  }

  return min;
}

std::size_t min_elements(const int matrix[][MAX_SIZE], 
                         std::size_t rows, 
                         std::size_t columns, 
                         int output[]) {
  for (std::size_t i = 0; i < rows; ++i) {
    output[i] = min_element_array(matrix[i], columns);
  }

  return rows;
}

void print_main_diagonal(const int matrix[][MAX_SIZE], std::size_t n) {
  for (std::size_t i = 0; i < n; ++i) {
    std::cout << matrix[i][i] << ' ';
  }
}

bool is_triangular(const int matrix[][MAX_SIZE], std::size_t n) {
  for (std::size_t i = 1; i < n; ++i) {
    for(std::size_t j = 0; j < n; ++j) {
      if(j < i && matrix[i][j]) {
        return false;
      }
    }
  }

  return true;
}

void transpose(const int matrix[][MAX_SIZE], 
               std::size_t rows, 
               std::size_t columns, 
               int destination[][MAX_SIZE]) {
  for (std::size_t i = 0; i < rows; ++i) {
    for (std::size_t j = 0; j < columns; ++j) {
      destination[j][i] = matrix[i][j];
    }
  }
}

void multiply(const int lhs[][MAX_SIZE], 
              std::size_t lhs_rows, 
              std::size_t lhs_columns, 
              const int rhs[][MAX_SIZE], 
              std::size_t rhs_columns,
              int destination[][MAX_SIZE]) {
  for (std::size_t i = 0; i < lhs_rows; ++i) {
    for (std::size_t j = 0; j < rhs_columns; ++j) {
      for (std::size_t k = 0; k < lhs_columns; ++k) {
        destination[i][j] += lhs[i][k] * rhs[k][j];
      }
    }
  }
}

void traverse_diagonally_up(const int matrix[][MAX_SIZE],
                            int columns,
                            int start_row,
                            int start_column) {
  while(start_row >= 0 && start_column != columns) {
    std::cout<< matrix[start_row][start_column] << ' ';
    --start_row;
    ++start_column;
  }
}

void traverse(const int matrix[][MAX_SIZE], 
              std::size_t rows, 
              std::size_t columns) {
  for (std::size_t i = 0; i < rows; ++i) {
    traverse_diagonally_up(matrix, columns, i, 0);
  }

  for (std::size_t j = 1; j < columns; ++j) {
    traverse_diagonally_up(matrix, columns, rows - 1, j);
  }
}

void traverse_rows(const int matrix[][MAX_SIZE], 
                   std::size_t steps,
                   std::size_t start_row,
                   std::size_t start_column,
                   bool right) {
  for (std::size_t i = 0; i < steps; ++i) {
    std::cout << matrix[start_row][right ? start_column + i : start_column - i] << ' ';
  } 
}

void traverse_columns(const int matrix[][MAX_SIZE],
                      std::size_t steps,
                      std::size_t start_row,
                      std::size_t start_column,
                      bool top) {
  for (std::size_t i = 0; i < steps; ++i) {
    std::cout << matrix[top ? start_row - i : start_row + i][start_column] << ' ';
  }
}

void traverse_spiral(const int matrix[][MAX_SIZE], std::size_t rows, std::size_t columns) {
  int steps_row = rows, steps_column = columns - 1;
  bool right = true, top = false;
  int start_row = 0, start_column = 0;

  while (steps_row > 0 || steps_column > 0) {
    traverse_rows(matrix, steps_row--, start_row, start_column, right);
    start_column = right ? start_column + steps_row : start_column - steps_row;
    start_row = right ? start_row + 1 : start_row - 1;

    traverse_columns(matrix, steps_column--, start_row, start_column, top);
    start_column = top ? start_column + 1 : start_column - 1; 
    start_row = top ? start_row - steps_column : start_row + steps_column;

    top = !top;
    right = !right;  
  }
}

int main() {
  int matrix[][MAX_SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

traverse_spiral(matrix, 3, 3); // -> 1 2 3 6 9 8 7 4 5
std::cout<<'\n';
  return 0;
}