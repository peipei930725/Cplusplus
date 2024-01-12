#include <iostream>

class T {
public:
  void print_var(int var)
  {
    std::cout << this->var << " " << var << "\n";
  }

  T()
      : var() {}

  int var;
};

int main()
{
  T t1;
  t1.print_var(100);
}