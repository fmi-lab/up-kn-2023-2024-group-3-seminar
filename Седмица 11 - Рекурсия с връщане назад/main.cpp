#include <cstddef>
#include <iostream>

bool candidates_goal(unsigned candidates[], std::size_t n, int target) {
  if (!target) {
    return true;
  }

  if (target < 0) {
    return false;
  }

  for (std::size_t i = 0; i < n; ++i) {
    if (candidates_goal(candidates, n, target - candidates[i])) {
      return true;
    }
  }

  return false;
}

bool is_valid_position(int canvas[][255], int x, int y, std::size_t rows,
                       std::size_t columns, int color) {
  return x >= 0 && x < rows && y >= 0 && y < columns && canvas[x][y] == color;
}

void flood_fill(int canvas[][255], std::size_t height, std::size_t width, int x,
                int y, int color) {
  int current_color = canvas[x][y];
  canvas[x][y] = color;

  if (is_valid_position(canvas, x + 1, y, height, width, current_color)) {
    flood_fill(canvas, height, width, x + 1, y, color);
  }

  if (is_valid_position(canvas, x - 1, y, height, width, current_color)) {
    flood_fill(canvas, height, width, x - 1, y, color);
  }

  if (is_valid_position(canvas, x, y + 1, height, width, current_color)) {
    flood_fill(canvas, height, width, x, y + 1, color);
  }

  if (is_valid_position(canvas, x, y - 1, height, width, current_color)) {
    flood_fill(canvas, height, width, x, y - 1, color);
  }
}

void print_matrix(int matrix[][255], std::size_t rows, std::size_t columns) {
  for (std::size_t i = 0; i < rows; ++i) {
    for (std::size_t j = 0; j < columns; ++j) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

bool winning_sequence_helper(int sequence[], std::size_t length, bool *removed,
                             int previous, std::size_t remaining) {
  if (!remaining) {
    return true;
  }

  for (std::size_t i = 0; i < length; ++i) {
    if (!removed[i] &&
        (sequence[i] % previous == 0 || previous % sequence[i] == 0)) {
      removed[i] = true;

      if (winning_sequence_helper(sequence, length, removed, sequence[i],
                                  remaining - 1)) {
        return true;
      }

      removed[i] = false;
    }
  }

  return false;
}

bool winning_sequence(int sequence[], std::size_t length) {
  bool *removed = new bool[length]{};

  for (std::size_t i = 0; i < length; ++i) {
    removed[i] = true;

    if (winning_sequence_helper(sequence, length, removed, sequence[i],
                                length - 1)) {
      delete[] removed;
      return true;
    }

    removed[i] = false;
  }

  delete[] removed;
  return false;
}

bool is_valid_position(int x, int y, std::size_t rows, std::size_t columns) {
  return x >= 0 && x < rows && y >= 0 && y < columns;
}

bool find_word(char crossword[][255], std::size_t rows, std::size_t cols, int x,
               int y, char word[], bool **visited) {
  if (!*word) {
    return true;
  }

  if (!is_valid_position(x, y, rows, cols) || visited[x][y] ||
      crossword[x][y] != *word) {
    return false;
  }

  visited[x][y] = true;

  if (find_word(crossword, rows, cols, x + 1, y, word + 1, visited)) {
    visited[x][y] = false;
    return true;
  }

  if (find_word(crossword, rows, cols, x - 1, y, word + 1, visited)) {
    visited[x][y] = false;
    return true;
  }

  if (find_word(crossword, rows, cols, x, y + 1, word + 1, visited)) {
    visited[x][y] = false;
    return true;
  }

  if (find_word(crossword, rows, cols, x, y - 1, word + 1, visited)) {
    visited[x][y] = false;
    return true;
  }

  visited[x][y] = false;

  return false;
}

unsigned find_words_in_crossword(char matrix[][255], std::size_t rows,
                                 std::size_t cols, char words[][255],
                                 std::size_t n) {
  bool **visited = new bool *[rows];
  for (std::size_t i = 0; i < rows; ++i) {
    visited[i] = new bool[cols]{};
  }

  unsigned counter = 0;

  for (std::size_t i = 0; i < n; ++i) {
    for (std::size_t j = 0; j < rows; ++j) {
      for (std::size_t k = 0; k < cols; ++k) {
        if (find_word(matrix, rows, cols, j, k, words[i], visited)) {
          ++counter;
          j = rows;
          k = cols;
        }
      }
    }
  }

  for (std::size_t i = 0; i < rows; ++i) {
    delete[] visited[i];
  }
  delete[] visited;
  return counter;
}

int main() {
  char matrix[][255] = {{'c', 'a', 't'}, {'w', 'h', 'o'}, {'w', 'i', 'n'}, {'c', 'a', 't'}};
  char words[][255] = {"cat", "hello", "what", "caca"};
  std::cout << find_words_in_crossword(matrix, 4, 3, words, 4)<<'\n'; // -> 2
                                                                // -> cat, what
  return 0;
}