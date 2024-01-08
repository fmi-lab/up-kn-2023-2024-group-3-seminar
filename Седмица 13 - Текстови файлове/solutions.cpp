#include <cstddef>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <ios>
#include <iostream>

constexpr std::size_t MAX_SIZE = 50;

struct Product {
  char name[MAX_SIZE];
  unsigned quantity;
  double price;
};

struct ProductArray {
  Product *data;
  std::size_t size;
  std::size_t capacity;
};

void print_file(const char *filename) {
  std::ifstream file(filename);

  char buff[MAX_SIZE]{};

  while (file >> buff) {
    std::cout << buff << ' ';
  }

  file.close();
}

std::size_t file_size(const char *filename) {
  std::ifstream file(filename);

  std::streampos start = file.tellg();
  file.seekg(0, std::ios::end);
  std::streampos end = file.tellg();
  file.seekg(start, std::ios::beg);

  std::size_t result = end - start;

  file.close();

  return result;
}

char *pad_right(const char *str, std::size_t size) {
  char *result = new char[size + 1]{};
  strcpy(result, str);

  int index = strlen(str);
  for (int i = index; i < size; ++i) {
    result[i] = '@';
  }

  return result;
}

void add_words(const char *filename) {
  std::fstream file(filename);

  char buff[MAX_SIZE]{};

  while (file >> buff) {
    if (strlen(buff) < 6) {
      std::streampos start = file.tellg();
      file.seekp(0, std::ios::end);

      char *padded = pad_right(buff, 6);
      file << ' ' << padded;
      delete[] padded;

      file.seekg(start);
    }
  }

  file.close();
}

ProductArray load_inventory(const char *inventory_filename) {
  std::ifstream inventory(inventory_filename);

  std::size_t n;
  inventory >> n;

  ProductArray array{
    new Product[n],
    0,
    n
  };

  for (std::size_t i = 0; i < n; ++i) {
    inventory >> array.data[i].name
              >> array.data[i].quantity
              >> array.data[i].price;
    ++array.size;
  }

  return array;
}

int main() {
  ProductArray array = load_inventory("inventory.txt");

  for (std::size_t i = 0; i < array.size; ++i) {
    std::cout<<array.data[i].name<<' '
             <<array.data[i].quantity << ' '
             <<array.data[i].price<<'\n';
  }

  delete [] array.data;

  // std::ofstream("inventory.txt", std::ios::trunc);

  return 0;
}