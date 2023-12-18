#include <iostream>

struct Employee {
  const char *name;
  const char *position;
  Employee *boss;
};

int main() {
  Employee director{"Todor", "director", nullptr};
  Employee pm{"Petar", "pm", &director};
  Employee tl{"Georgi", "tl", &pm};
  Employee tb{"Tanya", "tb", &pm};
  Employee employee{"Ivan", "employee", &tl};

  while (employee.boss) {
    std::cout << employee.name << ' ';
    employee = *employee.boss;
  }
  std::cout << employee.name << '\n';

  while (tb.boss) {
    std::cout << tb.name << ' ';
    tb = *tb.boss;
  }
  std::cout << tb.name << '\n';

  return 0;
}