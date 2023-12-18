#include <cstddef>
#include <cstdio>
#include <iostream>
#include <variant>

struct Array {
  int* data;
  std::size_t size;
  std::size_t capacity;
};

void resize(Array& array) {
  if(!array.capacity) {
    array.capacity = 1;
  }

  int* new_data = new int[array.capacity * 2];
  for (std::size_t i = 0; i < array.size; ++i) {
    new_data[i] = array.data[i];
  }

  delete[] array.data;
  array.data = new_data;
  array.capacity *= 2; 
}

void push_back(int element, Array& array) {
  if(array.size == array.capacity) {
    resize(array);
  }

  array.data[array.size++] = element;
}

void remove(int element, Array& array) {
  std::size_t i = 0;
  while (i < array.size && array.data[i] != element) {
    ++i;
  }

  if(i == array.size) {
    return;
  }

  for (std::size_t j = i; j < array.size - 1; ++j) {
    std::swap(array.data[j], array.data[j+1]);
  }

  --array.size;
}

int main() {
  Array arr{nullptr, 0, 0};

  for (std::size_t i = 0; i < 5; ++i) {
    push_back(i, arr);
  }

  remove(3, arr);
  remove(6, arr);

  for (std::size_t i = 0; i < arr.size; ++i) {
    std::cout<<arr.data[i]<<' ';
  }
  std::cout<<'\n';

  delete [] arr.data;
  return 0;
}