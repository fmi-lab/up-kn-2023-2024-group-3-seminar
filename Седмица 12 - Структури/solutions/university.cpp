#include <cstddef>
#include <cstring>
#include <iostream>

struct Mark {
  const char* subject;
  double score;
};

struct MarksArray {
  Mark* data;
  std::size_t size;
  std::size_t capacity;
};

struct Student {
  const char* name;
  int year;
  MarksArray marks;
};

struct StudentsArray {
  Student* data;
  std::size_t size;
  std::size_t capacity;
};

struct University {
  const char* name;
  StudentsArray students;
};

void resize_students(StudentsArray& array) {
  if(!array.capacity) {
    array.capacity = 1;
  }

  Student* new_data = new Student[array.capacity * 2];
  for (std::size_t i = 0; i < array.size; ++i) {
    new_data[i] = array.data[i];
  }

  delete[] array.data;
  array.data = new_data;
  array.capacity *= 2; 
}

void add_student(const Student& student, University& university) {
  if(university.students.size == university.students.capacity) {
    resize_students(university.students);
  }

  university.students.data[university.students.size++] = student;
}

void resize_marks(MarksArray& array) {
  if(!array.capacity) {
    array.capacity = 1;
  }

  Mark* new_data = new Mark[array.capacity * 2];
  for (std::size_t i = 0; i < array.size; ++i) {
    new_data[i] = array.data[i];
  }

  delete[] array.data;
  array.data = new_data;
  array.capacity *= 2; 
}

void push_back_mark(const Mark& mark, MarksArray& array) {
  if(array.size == array.capacity) {
    resize_marks(array);
  }

  array.data[array.size++] = mark;
}

void add_mark(const Mark& mark, const char* name, const University& university) {
  std::size_t i = 0;
  while (i < university.students.size && strcmp(name, university.students.data[i].name)) {
    ++i;
  }

  if(i == university.students.size) {
    return;
  }

  push_back_mark(mark, university.students.data[i].marks);
}

int main() {
  University university{"Sofia University", {nullptr, 0, 0}};
  Student student{"Gosho", 3, {nullptr, 0, 0}};
  Mark mark{"Introduction to Programming", 5.87};

  add_student(student, university);
  add_mark(mark, "Gosho", university);

  std::cout<< university.students.data[0].name << ' ' 
           << university.students.data[0].year << ' ' 
           << university.students.data[0].marks.data[0].subject << ' '
           << university.students.data[0].marks.data[0].score <<'\n';

  delete [] university.students.data[0].marks.data;
  delete [] university.students.data;
  return 0;
}